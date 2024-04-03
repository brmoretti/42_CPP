/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:06:51 by brmoretti         #+#    #+#             */
/*   Updated: 2024/04/02 14:19:46 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {

public:
	PhoneBook(void);
	~PhoneBook(void);

private:
	Contact				_contacts[8];
	unsigned short int	_n_contacts;

	void				_prompt(void);
	void				_add(unsigned short int index);
	void				_search(void) const;
	void				_print_phone_book(void) const;
	void				_print_phone_book_field(const std::string str) const;
};

#endif
