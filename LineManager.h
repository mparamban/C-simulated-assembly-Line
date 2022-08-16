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
#ifndef MS3_LINEMANAGER_H
#define MS3_LINEMANAGER_H

#include <iostream>
#include <vector>
#include "Workstation.h"

class LineManager
{
	std::vector<Workstation*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder;

public:
	LineManager(const std::string&, std::vector<Workstation*>&, std::vector<CustomerOrder>&);
	bool run(std::ostream& os);
	void displayCompletedOrders(std::ostream& os) const;
	void displayStations() const;
	void displayStationsSorted() const;
};

#endif // !MS3_LINEMANAGER_H
