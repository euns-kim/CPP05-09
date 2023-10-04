/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:38:16 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/04 17:25:29 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* Orthodox Canonical Form */

Bureaucrat::Bureaucrat(void) : _name("Defalt"), _grade(150)
{
	std::cout << PINK << "[Bureaucrat] Default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
	std::cout << PINK << "[Bureaucrat] Name & grade constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << PINK << "[Bureaucrat] Copy constructor called" << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &op)
{
	std::cout << PINK << "[Bureaucrat] Copy assignment operator called" << RESET << std::endl;
	if (this != &op)
	{
		_grade = op._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << PINK << "[Bureaucrat] Destructor called" << RESET << std::endl;
}

std::string const	&Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
}

void	Bureaucrat::incrementGrade(void)
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade -= 1;
}

void	Bureaucrat::decrementGrade(void)
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade += 1;
}

void	Bureaucrat::signForm(Form &f)
{
	try {
		f.beSigned(*this);
		std::cout << PINK << "* " << getName() << " signed " << f.getName() << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << PINK << "* " << getName() << " couldn't sign " << f.getName() << " because " << e.what() << RESET << std::endl;
	}
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw() {
    return ("\x1B[38;2;224;224;224m[Bureaucrat] Grade is too low\x1B[0m");
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw() {
    return ("\x1B[38;2;224;224;224m[Bureaucrat] Grade is too high\x1B[0m");
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &bureaucrat)
{
	return (o << PINK << "* " << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << RESET << std::endl);
}
