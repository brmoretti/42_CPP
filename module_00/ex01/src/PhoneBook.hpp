/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:06:51 by brmoretti         #+#    #+#             */
/*   Updated: 2024/04/05 11:00:19 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <sstream>

class PhoneBook
{

public:
	PhoneBook( void );
	~PhoneBook( void );

private:
	Contact				_contacts[8];
	unsigned short int	_n_contacts;

	void				_prompt( void );
	void				_add( unsigned short int index );
	void				_addAttribute( unsigned short int index, 
							std::string text, contact_prop prop );
	void				_search( void ) const;
	void				_printPhoneBook( void ) const;
	void				_printPhoneBookField( const std::string str ) const;
};

#endif
