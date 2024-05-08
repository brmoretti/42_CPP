/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prices.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:49:52 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/08 17:39:32 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRICES_HPP
# define PRICES_HPP

# include <string>
# include <map>
# include <fstream>
# include <exception>
# include <sstream>

# include <iostream>

class Prices
{
public:
	Prices(const char * file_path, char sep);
	~Prices();
	Prices(const Prices& rhs);
	Prices&		operator=(const Prices& rhs);

	const double &	operator[](const char * date) const;

private:
	Prices();

	std::map< std::string, double >	_map;
};

#endif
