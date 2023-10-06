/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:17:55 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/04 17:29:33 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* Orthodox Canonical Form */

AForm::AForm(void) : _name("Defalt"), _gradeToExecute(1), _gradeToSign(1), _isSigned(false)
{
	std::cout << ICE << "[AForm] Default constructor called" << RESET << std::endl;
}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute)
: _name(name), _gradeToExecute(gradeToExecute), _gradeToSign(gradeToSign), _isSigned(false)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();

	std::cout << ICE << "[AForm] Name & grades constructor called" << RESET << std::endl;
}

AForm::AForm(const AForm &copy)
: _name(copy._name), _gradeToExecute(copy._gradeToExecute), _gradeToSign(copy._gradeToSign), _isSigned(copy._isSigned)
{
	std::cout << ICE << "[AForm] Copy constructor called" << RESET << std::endl;
}

AForm &AForm::operator=(const AForm &op)
{
	std::cout << ICE << "[AForm] Copy assignment operator called" << RESET << std::endl;
	if (this != &op)
	{
		_isSigned = op._isSigned;
	}
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << ICE << "[AForm] Destructor called" << RESET << std::endl;
}

std::string const	&AForm::getName(void) const
{
	return (_name);
}

bool const	&AForm::getIsSigned(void) const
{
	return (_isSigned);
}

int	const	&AForm::getGradeToSign(void) const
{
	return (_gradeToSign);
}

int	const	&AForm::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

void	AForm::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const char	*AForm::GradeTooLowException::what(void) const throw() {
    return ("\x1B[38;2;255;204;229mgrade is too low\x1B[0m");
}

const char	*AForm::GradeTooHighException::what(void) const throw() {
    return ("\x1B[38;2;255;204;229mgrade is too high\x1B[0m");
}

std::ostream	&operator<<(std::ostream &o, const AForm &f)
{
	return (o << ICE << "* AForm name : " << f.getName() << std::endl \
	<< "* Grade to sign : " << f.getGradeToSign() << std::endl \
	<< "* Grade to execute : " << f.getGradeToExecute() << std::endl \
	<< "* Signed : " << (f.getIsSigned() ? "yes" : "no") << RESET << std::endl);
}
