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
#ifndef MS02_UTILITIES_H
#define MS02_UTILITIES_H
#include<iostream>
#include<string>
#include<algorithm>

class Utilities {

	size_t m_widthField = 1;
	static char m_delimiter;
public:
	void setFieldWidth(size_t newWidth);
	size_t getFieldWidth() const;
	std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(char newDelimiter);
	static char getDelimiter();
};
#endif // !MS02_UTILITIES_H
