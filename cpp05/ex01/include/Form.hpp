/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:56:44 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/03 19:25:24 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Form
{

	private:
		std::string const	_name;
		bool				_isSigned;
		int	const			_gradeToSign;
		int	const			_gradeToExecute;
		

	public:
		Form(void);
		Form(std::string const &name, int gradeToSign, int gradeToExecute);
		Form(const Form &copy);
		Form &operator=(const Form &op);
		~Form(void);

		std::string const	&getName(void) const;
		bool const			&getIsSigned(void) const;
		int const			&getGradeToSign(void) const;
		int const			&getGradeToExecute(void) const;
	
		void	beSigned(Bureaucrat const &b);

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

};

std::ostream	&operator<<(std::ostream &o, const Form &Form);

#endif