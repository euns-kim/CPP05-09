/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:26:04 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/06 19:57:20 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* Orthodox Canonical Form */

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon", 25, 5), _target("Default")
{
	std::cout << LIME << "[PresidentialPardonForm] Default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5), _target(target)
{
	std::cout << LIME << "[PresidentialPardonForm] Name & grades constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy._target)
{
	std::cout << LIME << "[PresidentialPardonForm] Copy constructor called" << RESET << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &op)
{
	std::cout << LIME << "[PresidentialPardonForm] Copy assignment operator called" << RESET << std::endl;
	if (this != &op)
	{
		_target = op._target;
		AForm::operator=(op);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << LIME << "[PresidentialPardonForm] Destructor called" << RESET << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	checkRequirements(executor);
	std::cout << LIME << "* [PresidentialPardonForm] " << _target << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}
