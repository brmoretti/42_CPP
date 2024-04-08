/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:50:10 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/07 23:35:22 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void )
{
	this->_n_contacts = 0;
	this->_prompt();
}

PhoneBook::~PhoneBook( void )
{	
}

void	PhoneBook::_prompt( void )
{
	std::string			buffer;
	
	std::cout << "Welcome to My Awesome Phonebook!\n" << std::endl;

	unsigned short int	index = 0;
	bool				exit = false;
	while (!exit) {
		std::cout << "What do you want to do? \n";
		std::cout << "ADD\n";
		std::cout << "SEARCH\n";
		std::cout << "EXIT\n";
		std::getline(std::cin, buffer);
		if (buffer == "ADD") {
			if (index == 8)
				index = 0;
			_add(index);
			index++;
		} else if (buffer == "SEARCH") {
			_search();
		} else if (buffer == "EXIT") {
			exit = true;
		} else {
			std::cout << "❌ Invalid input. Please try again.\n" << std::endl;
		}
	}
}

void	PhoneBook::_add( unsigned short int index )
{
	this->_addAttribute(index, "First name:", FIRST_NAME);
	this->_addAttribute(index, "Last name:", LAST_NAME);
	this->_addAttribute(index, "Nickname:", NICKNAME);
	this->_addAttribute(index, "Phone number:", PHONE_NUMBER);
	this->_addAttribute(index, "🤫 Darkest secret:", DARK_SECRET);
	if (this->_n_contacts < 8)
		this->_n_contacts++;
}

void	PhoneBook::_addAttribute( unsigned short int index, 
					std::string text, contact_prop prop )
{
	std::string	buffer;
	bool		b = false;
	
	while (!b) {
		std::cout << text << std::endl;
		std::getline(std::cin, buffer);
		b = PhoneBook::_contacts[index].setProperty(buffer, prop);
	}
}

void	PhoneBook::_search( void ) const
{
	if (this->_n_contacts == 0) {
		std::cout << "Phone book is still empty" << std::endl;
		return;
	}
	this->_printPhoneBook();
	std::string	buffer;
	std::cout << "Choose one contact:" << std::endl;
	std::getline(std::cin, buffer);
	std::stringstream	ss(buffer);
	int	buffer_int = -1;
	ss >> buffer_int;
	if (ss.fail() || buffer_int >= this->_n_contacts || buffer_int < 0) {
		std::cerr << "❌ Invalid index" << std::endl;
		return ;
	}
	this->_contacts[buffer_int].printContactInfo();
}

void	PhoneBook::_printPhoneBook( void ) const
{
	std::cout << "Index     |First Name|Last Name |Nickname  |" << std::endl;
	std::stringstream ss;
	short int i = -1;
	while (++i < this->_n_contacts) {
		ss << i;
		this->_printPhoneBookField(ss.str());
		ss.str("");
		ss.clear();
		this->_printPhoneBookField(this->_contacts[i].getProperty(FIRST_NAME));
		this->_printPhoneBookField(this->_contacts[i].getProperty(LAST_NAME));
		this->_printPhoneBookField(this->_contacts[i].getProperty(NICKNAME));
		std::cout << std::endl;
	}
}

void	PhoneBook::_printPhoneBookField( const std::string str ) const
{
	std::string	to_print;

	if (str.length() > 10)
		to_print = str.substr(0, 9) + '.';
	else
		to_print = str;
	std::cout << std::setw(10) << std::right << to_print << "|";
}
