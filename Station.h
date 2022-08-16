//------------------------------------------------------------------------------
//	Name: Mansoor Paramban
//	Student Id: 105034177
//	Student email: mparamban@myseneca.ca
//	Date: Nov 22, 2020
//	Purpose: MS02
//	Section: NHH
//------------------------------------------------------------------------------
/*
I have done all the coding by myself and only copied the code that the professor
provided to complete my workshops and assignments.
*/
//------------------------------------------------------------------------------
#ifndef MS02_STATION_H
#define MS02_STATION_H
#include<iostream>
#include<string>

class Station {

	unsigned int m_id;
	std::string m_name;
	std::string m_desc;
	int m_serialNumber;
	int m_stock;
	static size_t m_widthField;
	static unsigned int id_generator;
public:
	Station(const std::string&);
	const std::string& getItemName() const;
	unsigned int getNextSerialNumber();
	unsigned int getQuantity() const;
	void updateQuantity();
	void display(std::ostream& os, bool full) const;

};

#endif // !MS02_STATION_H
