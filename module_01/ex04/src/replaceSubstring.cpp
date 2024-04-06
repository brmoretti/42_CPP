/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceSubstring.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:22:01 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/06 14:38:31 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

std::string replaceSubstring(std::string str, const std::string& target,
	const std::string& replacement)
{
	size_t pos = 0;

	while ((pos = str.find(target, pos)) != std::string::npos) {
		str = str.substr(0, pos) + replacement +
			str.substr(pos + target.length());
		pos += replacement.length();
	}
	return str;
}
