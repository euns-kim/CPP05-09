/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:56:44 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/04 17:19:10 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

	private:
		std::string const	_name;
		int	const			_gradeToExecute;
		int	const			_gradeToSign;
		bool				_isSigned;

	public:
		AForm(void);
		AForm(std::string const &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &op);
		virtual ~AForm(void);

		std::string const	&getName(void) const;
		bool const			&getIsSigned(void) const;
		int const			&getGradeToSign(void) const;
		int const			&getGradeToExecute(void) const;
	
		void			beSigned(Bureaucrat const &b);
		virtual void	execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception
		{		
			public:
				const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class FormUnsignedException : public std::exception
		{
			public:
				const char	*what() const throw();
		};		

};

std::ostream	&operator<<(std::ostream &o, const AForm &AForm);

#endif
