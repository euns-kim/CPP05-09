/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:17:55 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/04 17:29:33 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* Orthodox Canonical Form */

Form::Form(void) : _name("Defalt"), _gradeToExecute(1), _gradeToSign(1), _isSigned(false)
{
	std::cout << ICE << "[Form] Default constructor called" << RESET << std::endl;
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute)
: _name(name), _gradeToExecute(gradeToExecute), _gradeToSign(gradeToSign), _isSigned(false)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();

	std::cout << ICE << "[Form] Name & grades constructor called" << RESET << std::endl;
}

Form::Form(const Form &copy)
: _name(copy._name), _gradeToExecute(copy._gradeToExecute), _gradeToSign(copy._gradeToSign), _isSigned(copy._isSigned)
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

void	Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const char	*Form::GradeTooLowException::what(void) const throw() {
    return ("\x1B[38;2;255;204;229mgrade is too low\x1B[0m");
}

const char	*Form::GradeTooHighException::what(void) const throw() {
    return ("\x1B[38;2;255;204;229mgrade is too high\x1B[0m");
}

std::ostream	&operator<<(std::ostream &o, const Form &f)
{
	return (o << ICE << "* Form name : " << f.getName() << std::endl \
	<< "* Grade to sign : " << f.getGradeToSign() << std::endl \
	<< "* Grade to execute : " << f.getGradeToExecute() << std::endl \
	<< "* Signed : " << (f.getIsSigned() ? "yes" : "no") << RESET << std::endl);
}
