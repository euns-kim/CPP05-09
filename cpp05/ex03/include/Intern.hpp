/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:13:12 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/06 21:13:19 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{

	public:
		Intern(void);
		Intern(std::string target);
		Intern(const Intern &copy);
		Intern &operator=(const Intern &op);
		~Intern(void);

		AForm	*makeForm(std::string formName, std::string target);
};

#endif
