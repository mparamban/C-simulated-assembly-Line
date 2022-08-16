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

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Utilities.h"
#include "Station.h"

size_t Station::m_widthField = 0;
unsigned int Station::id_generator = 1;

Station::Station(const std::string& str) : m_id(id_generator)
{
	Utilities u{};
	size_t next_pos = 0;
	bool more = true;

	try
	{
		m_name = u.extractToken(str, next_pos, more);
		m_serialNumber = std::stoi(u.extractToken(str, next_pos, more));
		m_stock = std::stoi(u.extractToken(str, next_pos, more));
		m_widthField = std::max(u.getFieldWidth(), m_widthField);
		m_desc = u.extractToken(str, next_pos, more);
	}
	catch (std::string& error)
	{
		std::cout << error;
	}
	++id_generator;
}

const std::string& Station::getItemName() const
{
	return m_name;
}

unsigned int Station::getNextSerialNumber()
{
	return m_serialNumber++;
}

unsigned int Station::getQuantity() const
{
	return m_stock;
}

void Station::updateQuantity()
{
	m_stock--;
	if (m_stock < 0) {
		m_stock = 0;
	}
}

void Station::display(std::ostream& os, bool full) const
{
	std::ios format(nullptr);
	format.copyfmt(std::cout);

	os << std::right;
	os << "[";
	os << std::setw(3);
	os << std::setfill('0');
	os << m_id << "] ";

	os << std::left;
	os << "Item: ";
	os << std::setw(m_widthField);
	os << std::setfill(' ');
	os << m_name;
	os << std::right;

	os << " [";
	os << std::setw(6);
	os << std::setfill('0');
	os << m_serialNumber << "]";
	os << std::left;

	if (full)
	{
		os << " Quantity: ";
		os << std::setw(m_widthField);
		os << std::setfill(' ');
		os << m_stock;

		os << " Description: ";
		os.copyfmt(format);
		os << m_desc << std::endl;

	}
	else
	{
		os << std::endl;
	}
}


