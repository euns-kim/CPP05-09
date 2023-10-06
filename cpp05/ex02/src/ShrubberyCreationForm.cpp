/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:01:00 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/06 17:20:58 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* Orthodox Canonical Form */

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreation", 145, 137), _target("Default")
{
	std::cout << HERB << "[ShrubberyCreationForm] Default constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", 145, 137), _target(target)
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
		AForm::operator=;
	}
	return (*this);
}
