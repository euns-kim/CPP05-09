/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:01:00 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/06 20:32:44 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* Orthodox Canonical Form */

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation", 145, 137), _target("Default")
{
	std::cout << HERB << "[ShrubberyCreationForm] Default constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation", 145, 137), _target(target)
{
	std::cout << HERB << "[ShrubberyCreationForm] Name & grades constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{
	std::cout << HERB << "[ShrubberyCreationForm] Copy constructor called" << RESET << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &op)
{
	std::cout << HERB << "[ShrubberyCreationForm] Copy assignment operator called" << RESET << std::endl;
	if (this != &op)
	{
		_target = op._target;
		AForm::operator=(op);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << HERB << "[ShrubberyCreationForm] Destructor called" << RESET << std::endl;
}

void	ShrubberyCreationForm::printTree(std::ostream &ofs) const
{
	ofs
	<< std::endl
	<< "         #" << std::endl
	<< "        ***" << std::endl
	<< "       *#*O*" << std::endl
	<< "      **O****" << std::endl
	<< "     *#**O****" << std::endl
	<< "    *O*#**O**#**" << std::endl
	<< "   *#**O*#**#****" << std::endl
	<< "  ***O*#*O****O*#*" << std::endl
	<< " **O#**O**#*O**#***" << std::endl
	<< "       | o  |" << std::endl
	<< "       |  o |" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	checkRequirements(executor);

	std::ofstream	ofs(_target + "_shrubbery");
	if (!ofs.is_open())
		throw FileOpenErrorException();
	printTree(ofs);
	ofs.close();

	std::cout << HERB << "* [ShrubberyCreationForm] Shrubbery has been successfully created at " << _target << RESET << std::endl;
}

const char	*ShrubberyCreationForm::FileOpenErrorException::what(void) const throw() {
    return ("\x1B[38;2;224;224;224mfile could not be opened properly\x1B[0m");
}
