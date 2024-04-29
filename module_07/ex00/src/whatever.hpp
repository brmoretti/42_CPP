/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:06:49 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/29 16:41:09 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void	swap(T & x, T & y)
{
	T	tmp;

	tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
T const &	min(T const & x, T const & y)
{
	return x < y ? x : y;
}

template <typename T>
T const &	max(T const & x, T const & y)
{
	return x > y ? x : y;
}
