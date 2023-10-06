/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:25:00 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/06 20:34:21 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

using std::cout;
using std::endl;

int main(void)
{
	{
		Bureaucrat b("Cat", 70);
		cout << b << endl;

		ShrubberyCreationForm sc("home");
		cout << sc << endl;

		b.signForm(sc);
		b.executeForm(sc);

		RobotomyRequestForm br("humankind");
		cout << br << endl;

		b.signForm(br);
		b.executeForm(br);

		PresidentialPardonForm pp("prisioner");
		cout << pp << endl;

		b.signForm(pp);
		b.executeForm(pp);
	}
	{
		Bureaucrat b("Pig", 15);
		cout << b << endl;

		ShrubberyCreationForm sc("school");
		// cout << sc << endl;

		b.signForm(sc);
		b.executeForm(sc);

		RobotomyRequestForm br("bread");
		// cout << br << endl;

		b.signForm(br);
		b.executeForm(br);

		PresidentialPardonForm pp("traveler");
		// cout << pp << endl;

		b.signForm(pp);
		b.executeForm(pp);
	}
	{
		Bureaucrat b("Cow", 1);
		cout << b << endl;

		ShrubberyCreationForm sc("garden");
		// cout << sc << endl;

		// b.signForm(sc);
		b.executeForm(sc);

		RobotomyRequestForm br("sense");
		// cout << br << endl;

		b.signForm(br);
		b.executeForm(br);

		PresidentialPardonForm pp("nuts");
		// cout << pp << endl;

		b.signForm(pp);
		b.executeForm(pp);
	}
}
