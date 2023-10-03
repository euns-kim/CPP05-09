/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:17:55 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/03 19:26:58 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* Orthodox Canonical Form */

Form::Form(void) : _name("Defalt"), _gradeToSign(1), _gradeToExecute(1), _isSigned(false)
{
	std::cout << ICE << "[Form] Default constructor called" << RESET << std::endl;
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute)
: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false)
{
	if (_gradeToSign < 1)
		throw GradeTooHighException();
	else if (_gradeToSign >150)
		throw GradeTooLowException();

	if (_gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToExecute > 150)
		throw GradeTooLowException();

	std::cout << ICE << "[Form] Name & grades constructor called" << RESET << std::endl;
}

Form::Form(const Form &copy)
: _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute), _isSigned(copy._isSigned)
{
	std::cout << ICE << "[Form] Copy constructor called" << RESET << std::endl;
}

Form &Form::operator=(const Form &op)
{
	std::cout << ICE << "[Form] Copy assignment operator called" << RESET << std::endl;
	if (this != &op)
	{
		_isSigned = op._isSigned;
	}
	return (*this);
}

Form::~Form(void)
{
	std::cout << ICE << "[Form] Destructor called" << RESET << std::endl;
}

std::string const	&Form::getName(void) const
{
	return (_name);
}

bool const	&Form::getIsSigned(void) const
{
	return (_isSigned);
}

int	const	&Form::getGradeToSign(void) const
{
	return (_gradeToSign);
}

int	const	&Form::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

const char	*Form::GradeTooLowException::what(void) const throw() {
    return ("\x1B[38;2;224;224;224m[Form] Grade too low\x1B[0m");
}

const char	*Form::GradeTooHighException::what(void) const throw() {
    return ("\x1B[38;2;224;224;224m[Form] Grade too high\x1B[0m");
}
