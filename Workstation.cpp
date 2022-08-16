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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Utilities.h"
#include "Station.h"
#include "Workstation.h"

Workstation::Workstation(const std::string& str) :Station(str) {
	m_pNextStation = nullptr;
}

void Workstation::runProcess(std::ostream& os) {
	if (m_orders.empty()) {
		return;
	}

	m_orders.front().fillItem(*this, os);
}

bool Workstation::moveOrder() {

	if (m_orders.empty()) {
		return false;
	}

	if (m_orders.front().isItemFilled(getItemName()) == true) {
		*m_pNextStation += std::move(m_orders.front());

		m_orders.pop_front();
		return true;
	}
	else {
		return false;
	}
}

void Workstation::setNextStation(Workstation& station) {

	m_pNextStation = &station;
}

const Workstation* Workstation::getNextStation() const {
	return m_pNextStation;
}

bool Workstation::getIfCompleted(CustomerOrder& order) {
	if (m_orders.empty()) {
		return false;
	}
	if (m_orders.front().isOrderFilled()) {
		order = std::move(m_orders.front());

		m_orders.pop_front();
		return true;
	}
	else {
		return false;
	}

}

void Workstation::display(std::ostream& os) const {

	if (m_pNextStation == nullptr)
		os << getItemName() << " --> END OF LINE" << std::endl;
	else
		os << getItemName() << " --> " << m_pNextStation->getItemName() << std::endl;
}


Workstation& Workstation::operator+=(CustomerOrder&& aa) {

	m_orders.push_back(std::move(aa));

	return *this;
}
