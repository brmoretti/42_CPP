/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:34:04 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/13 18:15:34 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(void)
{
	PmergeMe	fj; // Remove the parentheses after "PmergeMe fj" to declare an object instead of a function pointer.

	fj.addElement(4);
	fj.addElement(1);
	fj.addElement(3);
	fj.addElement(2);
	fj.addElement(17);
	fj.addElement(10);
	fj.addElement(0);
	fj.addElement(5);
	fj.addElement(7);
	fj.addElement(6);
	fj.addElement(9);
	fj.addElement(8);
	fj.addElement(11);
	fj.addElement(12);
	fj.sortFordJohnson();

	return (0);
}
