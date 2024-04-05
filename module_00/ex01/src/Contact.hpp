/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:27:57 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/05 11:03:51 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

typedef enum	e_property
{
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	DARK_SECRET
}	contact_prop;

class Contact
{

public:
	Contact( void );
	~Contact( void );

	std::string	getProperty( contact_prop property ) const;
	bool		setProperty( std::string str, contact_prop property );
	void		printContactInfo( void ) const;

private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;

	bool		_validPhoneNumber( std::string phone_number ) const;
};

#endif
