/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:24:32 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/10 17:25:18 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Test
# define Test

class Test
{
public:
	Test();
	~Test();
	Test(const Test & rhs);
	Test& operator=(const Test & rhs);

private:
	// Add your public members here
};

#endif
