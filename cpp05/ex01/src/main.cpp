/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:25:00 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/04 17:35:46 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

using std::cout;
using std::endl;

int main(void)
{
	{
		Bureaucrat	b("W", 30);
		cout << b << endl;

		Form	f("Chance", 100, 40);
		cout << f << endl;

		b.signForm(f);
		cout << f << endl;
	}
	cout << endl;
	{
		Bureaucrat	b("W", 30);
		cout << b << endl;

		Form	f("Chance", 30, 40);
		cout << f << endl;

		b.signForm(f);
		cout << f << endl;
	}
	cout << endl;
	{
		Bureaucrat	b("W", 30);
		cout << b << endl;

		Form	f("Chance", 15, 40);
		cout << f << endl;

		b.signForm(f);
		cout << f << endl;
	}
	cout << endl;
	{
		try {
			Form	f("Exception", 0, 30);
			cout << f << endl;
		} catch (std::exception &e) {
			cout << "Exception caught: " << e.what() << endl;
		}
	}
	cout << endl;
	{
		try {
			Form	f("Exception", 1, 151);
			cout << f << endl;
		} catch (std::exception &e) {
			cout << "Exception caught: " << e.what() << endl;
		}
	}
}
