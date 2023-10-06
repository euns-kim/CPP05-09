/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:15:22 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/06 17:20:31 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* Orthodox Canonical Form */

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequest", 72, 45), _target("Default")
{
	std::cout << SKY << "[RobotomyRequestForm] Default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest", 72, 45), _target(target)
{
	std::cout << SKY << "[RobotomyRequestForm] Name & grades constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target)
{
	std::cout << SKY << "[RobotomyRequestForm] Copy constructor called" << RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &op)
{
	std::cout << SKY << "[RobotomyRequestForm] Copy assignment operator called" << RESET << std::endl;
	if (this != &op)
	{
		_target = op._target;
		AForm::operator=;
	}
	return (*this);
}
