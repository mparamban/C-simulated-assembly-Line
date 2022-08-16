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
#ifndef MS2_CUSTOMERORDER_H
#define MS2_CUSTOMERORDER_H

#include <iostream>

struct Item {
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_isFilled = false;
	Item(const std::string& src) : m_itemName(src) {};
};

class CustomerOrder
{
private:
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem{}; 
	Item** m_lstItem{}; 
	static size_t m_widthField; 

public:
	CustomerOrder();
	CustomerOrder(const std::string&);
	CustomerOrder(const CustomerOrder&);
	CustomerOrder& operator=(const CustomerOrder&) = delete; 
	CustomerOrder(CustomerOrder&&) noexcept; 
	CustomerOrder& operator=(CustomerOrder&&) noexcept; 
	~CustomerOrder(); 
	bool isOrderFilled() const;
	bool isItemFilled(const std::string& itemName) const;
	void fillItem(Station& station, std::ostream& os) const;
	void display(std::ostream& os) const; 

};
#endif // !MS2_CUSTOMERORDER_H
