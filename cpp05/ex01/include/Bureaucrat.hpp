/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:14:54 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/03 19:04:26 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "Form.hpp"

# define RESET	"\x1B[0m"
# define PINK	"\x1B[38;2;255;204;229m"
# define ORANGE	"\x1B[38;2;255;178;102m"
# define PEACH	"\x1B[38;2;255;153;153m"
# define LIME	"\x1B[38;2;204;255;204m"
# define LEMON	"\x1B[38;2;229;229;204m"
# define SKY	"\x1B[38;2;204;229;255m"
# define ICE	"\x1B[38;2;204;255;255m"
# define HERB	"\x1B[38;2;204;255;229m"
# define GREY	"\x1B[38;2;224;224;224m"

class Bureaucrat
{

	private:
		std::string const	_name;
		int					_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &op);
		~Bureaucrat(void);

		std::string const	&getName(void) const;
		int					getGrade(void) const;

		void	setGrade(int grade);

		void	incrementGrade(void);
		void	decrementGrade(void);

		void	signForm(Form const &f);

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

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &bureaucrat);

#endif