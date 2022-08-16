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
#ifndef MS3_WORKSTATION_H
#define MS3_WORKSTATION_H

#include <iostream>
#include <deque>
#include <string>
#include "Station.h"
#include "CustomerOrder.h"
class Workstation :
	public Station
{
	std::deque<CustomerOrder> m_orders;
	Workstation* m_pNextStation;

public:
	Workstation(const std::string&);
	Workstation(const Workstation& p2) = delete;
	Workstation& operator=(const Workstation& other) = delete;
	Workstation(Workstation&& a) noexcept = delete;
	Workstation& operator=(Workstation&& a) noexcept = delete;
	void runProcess(std::ostream&);
	bool moveOrder();
	void setNextStation(Workstation& station);
	const Workstation* getNextStation() const;
	bool getIfCompleted(CustomerOrder& order);
	void display(std::ostream&)const;
	Workstation& operator+=(CustomerOrder&&);

};

#endif // !MS3_WORKSTATION_H
