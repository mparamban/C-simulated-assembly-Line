//------------------------------------------------------------------------------
//	Name: Mansoor Paramban
//	Student Id: 105034177
//	Student email: mparamban@myseneca.ca
//	Date: Nov 28, 2020
//	Purpose: MS03
//	Section: NHH
//------------------------------------------------------------------------------
/*
I have done all the coding by myself and only copied the code that the professor
provided to complete my workshops and assignments.
*/
//------------------------------------------------------------------------------
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include "Utilities.h"
#include "Station.h"
#include "LineManager.h"
#include"CustomerOrder.h"

LineManager::LineManager(const std::string& filename, std::vector<Workstation*>& v_workstation, std::vector<CustomerOrder>& v_order) {
	std::ifstream file(filename);
	if (!file)
		throw std::string("Unable to open [") + filename + "] file.";

	std::string str1;
	std::string temp1;
	std::string temp2;
	Utilities utility;
	size_t next_pos = 0;
	bool more = true;
	Workstation* firstW;
	Workstation* secondW;

	while (!file.eof())
	{
		std::getline(file, str1);
		temp1 = utility.extractToken(str1, next_pos, more);
		if (more) {
			temp2 = utility.extractToken(str1, next_pos, more);
		}
		else {
			temp2 = "";
		}

		firstW = nullptr;
		secondW = nullptr;

		for (auto& i : v_workstation)
		{
			if (i->getItemName() == temp1) {
				firstW = i;
			}
			if (!temp2.empty() && i->getItemName() == temp2) {
				secondW = i;
			}
		}

		if (secondW != nullptr) {
			firstW->setNextStation(*secondW);
		}

	}

	for (std::size_t i = 0; i < v_order.size(); ++i) {
		ToBeFilled.push_back(std::move(v_order[i]));
	}

	for (std::size_t i = 0; i < v_workstation.size(); ++i) {
		AssemblyLine.push_back(v_workstation[i]);
	}

	m_cntCustomerOrder = v_order.size();


}

bool LineManager::run(std::ostream& os) {
	static size_t count = 1;
	os << "Line Manager Iteration: " << count << std::endl;
	count++;

	if (!ToBeFilled.empty()) {
		int start = 0;
		for (std::size_t i = 0; i < AssemblyLine.size(); ++i) {
			start = i;
			for (std::size_t j = 0; j < AssemblyLine.size(); ++j) {

				if (AssemblyLine[j]->getNextStation() != nullptr && AssemblyLine[i]->getItemName().compare(AssemblyLine[j]->getNextStation()->getItemName()) == 0) {
					start = -1;
				}
			}

			if (start != -1) {
				break;
			}
		}

		*AssemblyLine[start] += std::move(ToBeFilled.front());
		ToBeFilled.pop_front();

	}

	for (std::size_t i = 0; i < AssemblyLine.size(); ++i) {
		AssemblyLine[i]->runProcess(os);
	}

	for (std::size_t i = 0; i < AssemblyLine.size(); ++i) {
		if (AssemblyLine[i]->getNextStation() == nullptr)
		{
			CustomerOrder tmp;
			if (AssemblyLine[i]->getIfCompleted(tmp)) {
				Completed.push_back(std::move(tmp));
			}
		}
		else {
			AssemblyLine[i]->moveOrder();
		}
	}

	if (Completed.size() == m_cntCustomerOrder) {
		return true;
	}
	else
		return false;
}

void LineManager::displayCompletedOrders(std::ostream& os) const {
	for (std::size_t i = 0; i < Completed.size(); ++i) {
		Completed[i].display(os);
	}
}

void LineManager::displayStations() const {
	for (std::size_t i = 0; i < AssemblyLine.size(); ++i) {
		AssemblyLine[i]->display(std::cout);
	}
}

void LineManager::displayStationsSorted() const {
	auto start = 0;
	for (std::size_t i = 0; i < AssemblyLine.size(); ++i) {
		start = i;
		for (std::size_t j = 0; j < AssemblyLine.size(); ++j) {

			if (AssemblyLine[j]->getNextStation() != nullptr && AssemblyLine[i]->getItemName() == AssemblyLine[j]
				->getNextStation()->
				getItemName()) {
				start = -1;
			}
		}

		if (start != -1) {
			break;
		}
	}

	const Workstation* begin = AssemblyLine[start];

	while (begin != nullptr) {
		begin->display(std::cout);
		begin = begin->getNextStation();
	}
}
