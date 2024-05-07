/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:49:52 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/07 17:07:16 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATABASE_HPP
# define DATABASE_HPP

# include <string>
# include <map>
# include <fstream>
# include <exception>
# include <sstream>

class Database
{
public:
	Database(std::string& file_path, char sep);
	~Database();
	Database(const Database& rhs);
	Database&	operator=(const Database& rhs);

private:
	Database();

	std::string						_path;
	char							_sep;
	std::map< std::string, double >	_map;

};

#endif
