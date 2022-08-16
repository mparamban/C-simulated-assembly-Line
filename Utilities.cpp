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
#include <algorithm>
#include <stdexcept>
#include "Utilities.h"

char Utilities::m_delimiter = ' ';

void Utilities::setFieldWidth(size_t newWidth){
	m_widthField = newWidth;
}

size_t Utilities::getFieldWidth() const{
	return m_widthField;
}

std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	std::string tmp = "";
	size_t first_pos = next_pos;

	next_pos = str.find(m_delimiter, first_pos);

	if (next_pos == std::string::npos) {
		tmp = str.substr(first_pos);
		m_widthField = std::max(tmp.length(), m_widthField);
		more = false;
	}
	else if (first_pos == next_pos)
	{
		more = false;
		throw "No token between delimiters!";
	}
	else {
		tmp = str.substr(first_pos, next_pos - first_pos);
		m_widthField = std::max(tmp.length(), m_widthField);
		more = true;
	}
	next_pos++;
	return tmp;

}

void Utilities::setDelimiter(char newDelimiter) {
	m_delimiter = newDelimiter;
}

char Utilities::getDelimiter() {
	return m_delimiter;
}
