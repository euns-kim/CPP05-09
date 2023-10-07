/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:25:00 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/07 14:09:36 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

using std::cout;
using std::endl;

int main(void)
{
	cout << endl;
	{
		Intern	someRandomIntern;
		AForm	*rrf;

		rrf = someRandomIntern.makeForm("shrubbery creation", "hill");
		cout << *rrf << endl;
		delete rrf;
	}
	cout << endl;
	{
		Intern	someRandomIntern;
		AForm	*rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "my life");
		cout << *rrf << endl;
		delete rrf;
	}
	cout << endl;
	{
		Intern	someRandomIntern;
		AForm	*rrf;

		rrf = someRandomIntern.makeForm("presidential pardon", "teddy bear");
		cout << *rrf << endl;
		delete rrf;
	}
	cout << endl;
	{
		Intern	someRandomIntern;
		AForm	*rrf;

		rrf = someRandomIntern.makeForm("some random intern", "red light");
		if (rrf == NULL)
			std::cerr << GREY << "!! Returned pointer is empty" << RESET << endl;
	}
	cout << endl;
}
