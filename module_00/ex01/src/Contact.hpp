/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:27:57 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/05 10:19:11 by bmoretti         ###   ########.fr       */
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

	std::string	get_property( contact_prop property ) const;
	bool		set_property( std::string str, contact_prop property );
	void		print_contact_info( void ) const;

private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;

	bool		_valid_phone_number( std::string phone_number ) const;
};

#endif
