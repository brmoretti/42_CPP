/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:49:52 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/16 15:07:00 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>
# include <fstream>
# include <exception>
# include <sstream>

# include <iostream>

class BitcoinExchange
{
public:
	BitcoinExchange(const char * file_path, char sep);
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& rhs);
	BitcoinExchange&		operator=(const BitcoinExchange& rhs);

	const double &	operator[](const char * date) const;

private:
	BitcoinExchange();

	std::map< std::string, double >	_map;
};

#endif
