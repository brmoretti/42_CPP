/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:43:29 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/25 01:41:23 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# define YELLOW(text) "\033[33m" << text << "\033[0m"

# define ASCII_TREES \
"                                ======. ." \
"                             @====.....====" \
"                           =.=....-==@@=.@=-" \
"                          ==.=@@@@@@@@@@@@@@" \
"                           @#@@==#========*" \
"                             @@@@#@@*@@@@@" \
"                         .====.-==@*@==.---==" \
"          .-...=       =-=.....==..=.......===@" \
"        @@====+@%@@   .=.:=@#@@@@@@==@@@@@@@@@        ." \
"    .=...:=@@=......=:  @=@@@@@=..*.=@@====*#    .=..======...=." \
"  ==.%====.....==*@+==@@  +=..*#@=....===@%    ======.....========" \
"  @@@#===@@@@@%@=:...-==@ .=-@@:..==*@===+   .-..@=@=.=========@@=.=." \
" =....====....-=@@@@@@@@@@ %=@@@=@=@+=+@@@: =-.=:....=..........=-.==." \
" @@@@@@@#=@@@@@==...==@@*- .*@@@**@*@@@@+  ..=-...==@===@=========@.==" \
"  +@@==-==.....==@==@@@:      =@***===.=  @=@====@@@@@==*@@@@@===@==@=" \
"    @@@=@@@@===@@@@@@@@         **.      .=@@@@@@@@@@@*@*#@@-@@+@@=.=" \
"      +@%@@@@@@@@@:==           **      .=@=#@@*@@*@**@=@*.@*.=@*..-=" \
"           @=:==                *#       .%@=@@@@@=@*@.#.@.@.@@@=@===*" \
"           .****                *%:        =@%@=*@=*=.=..+-.==+@@@+=-=" \
"            @*=                 *#             .==***:*@: *%*" \
"            @*@                 @@                   *:*" \
"            @*@                 @@                    *=" \
"            @@@                @@@                   *.-" \
"            @@@                @@@@                  @***"

# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string & target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& rhs);

	void	execute(Bureaucrat &bureaucrat) const;

	class FileAlreadyExist : public std::exception
	{
		public:
			virtual const char* what(void) const throw();
	};

	class FailedToOpen : public std::exception
	{
		public:
			virtual const char* what(void) const throw();
	};

private:
	static const int	_SIGN_GRADE = 145;
	static const int	_EXEC_GRADE = 137;

	const std::string	_target;
};

#endif
