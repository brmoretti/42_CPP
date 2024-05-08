/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trimSpaces.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:47:09 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/08 18:02:23 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <algorithm>
#include <string>

bool	notSpace(char c)
{
	return !std::isspace(static_cast<unsigned char>(c));
}

void	trimSpaces(std::string& s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), notSpace));
	s.erase(std::find_if(s.rbegin(), s.rend(), notSpace).base(), s.end());
}
