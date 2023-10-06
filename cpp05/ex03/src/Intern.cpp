/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:13:02 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/06 21:46:08 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* Orthodox Canonical Form */

Intern::Intern(void)
{
	std::cout << PEACH << "[Intern] Default constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
	std::cout << PEACH << "[Intern] Copy constructor called" << RESET << std::endl;
}

Intern &Intern::operator=(const Intern &op)
{
	(void) op;
	std::cout << PEACH << "[Intern] Copy assignment operator called" << RESET << std::endl;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << PEACH << "[Intern] Destructor called" << RESET << std::endl;
}

AForm	*Intern::makeForm(std::string formName, std::string target)
{
	AForm		*ret = NULL;

	int			formIdx = 3;
	std::string	Form[3] = { "shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 4; i++)
	{
		if (formName == Form[i])
		{
			formIdx = i;
			break;
		}
	}

	switch (formIdx)
	{
		case 0:
			std::cout << PEACH << "* Intern creates " << formName << RESET << std::endl;
			ret = new ShrubberyCreationForm(target);
			break;

		case 1:
			std::cout << PEACH << "* Intern creates " << formName << RESET << std::endl;
			ret = new RobotomyRequestForm(target);
			break;

		case 2:
			std::cout << PEACH << "* Intern creates " << formName << RESET << std::endl;
			ret = new PresidentialPardonForm(target);
			break;

		default:
			std::cerr << GREY << "* Intern could not make form because there is no form with the name given" << RESET << std::endl;
			break;
	}
	
	return (ret);
}