/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:26:04 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/06 17:26:06 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* Orthodox Canonical Form */

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardon", 25, 5), _target("Default")
{
	std::cout << SKY << "[PresidentialPardonForm] Default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon", 25, 5), _target(target)
{
	std::cout << SKY << "[PresidentialPardonForm] Name & grades constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy._target)
{
	std::cout << SKY << "[PresidentialPardonForm] Copy constructor called" << RESET << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &op)
{
	std::cout << SKY << "[PresidentialPardonForm] Copy assignment operator called" << RESET << std::endl;
	if (this != &op)
	{
		_target = op._target;
		AForm::operator=;
	}
	return (*this);
}
