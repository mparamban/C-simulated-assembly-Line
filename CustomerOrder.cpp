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
#include "CustomerOrder.h"

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder() {
	m_name = "";
	m_product = "";
	m_cntItem = 0;
	m_lstItem = nullptr;
}

CustomerOrder::CustomerOrder(const std::string& order) : m_cntItem(0), m_lstItem(nullptr){
	Utilities u{}; 
	size_t nextPos = 0; 
	bool more = true;

	try{
		m_name = u.extractToken(order, nextPos, more);
		m_product = u.extractToken(order, nextPos, more); 
		m_cntItem = std::count(order.begin(), order.end(), Utilities::getDelimiter()) - 1; 

		m_lstItem = new Item * [m_cntItem];
		for (size_t i = 0; i < m_cntItem; ++i){
			m_lstItem[i] = new Item(u.extractToken(order, nextPos, more));
		}
		m_widthField = std::max(u.getFieldWidth(), m_widthField);
	}
	catch (std::string& error){
		std::cout << error;
	}

}

CustomerOrder::CustomerOrder(const CustomerOrder& c){
	throw std::runtime_error("Copy is not allowed."); ;
}

CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept{
	*this = std::move(src);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& mv) noexcept{
	if (this != &mv){
		if (m_lstItem != nullptr) {
			for (size_t i = 0; i < m_cntItem; i++){
				delete m_lstItem[i];
			}
		}

		delete[] m_lstItem;

		m_name = mv.m_name;
		m_product = mv.m_product;
		m_cntItem = mv.m_cntItem;

		m_lstItem = mv.m_lstItem;
		mv.m_lstItem = nullptr;
	}
	return *this;
}

CustomerOrder::~CustomerOrder(){
	if (m_lstItem != nullptr) {
		for (size_t i = 0; i < m_cntItem; i++) {
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
	}
}

bool CustomerOrder::isOrderFilled() const{
	bool valid = true;
	for (size_t i = 0; i < m_cntItem && valid; i++) {

		if (m_lstItem[i]->m_isFilled == false) {
			valid = false;
		}
	}

	return valid;
}

bool CustomerOrder::isItemFilled(const std::string& itemName) const{
	bool valid = true;
	for (size_t i = 0; i < m_cntItem && valid; i++) {
		if (m_lstItem[i]->m_itemName == itemName) {

			valid = m_lstItem[i]->m_isFilled;
		}
	}
	return valid;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os) const{
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == station.getItemName()) {
			if (station.getQuantity() > 0) {
				station.updateQuantity();
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[i]->m_isFilled = true;
				os << "    Filled " << m_name;
				os << ", " << m_product;
				os << " [" << m_lstItem[i]->m_itemName;
				os << "]" << std::endl;
			}
			else {
				os << "    Unable to fill NAME, PRODUCT ";
				os << m_lstItem[i]->m_itemName << std::endl;
			}
		}
	}
}

void CustomerOrder::display(std::ostream& os) const{
	auto itemChecker = [&](const size_t& it) {return (m_lstItem[it]->m_isFilled ? "FILLED" : "MISSING"); };
	os << m_name << " - " << m_product << std::endl;

	for (size_t i = 0; i < m_cntItem; ++i) {
		os << "[";
		os << std::setfill('0') << std::right << std::setw(6);
		os << m_lstItem[i]->m_serialNumber << "] ";

		os << std::setfill(' ') << std::left << std::setw(m_widthField);
		os << m_lstItem[i]->m_itemName << " - ";

		os << itemChecker(i) << std::endl;
	}
}
