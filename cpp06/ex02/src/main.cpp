/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:17:10 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/13 19:54:48 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "ERROR" << std::endl;
}

void	identify(Base &p)
{	
	try {
		static_cast<void>(dynamic_cast<A &>(p));
		std::cout << "A" << std::endl;
	} catch (...) {
		try {
			static_cast<void>(dynamic_cast<B &>(p));
			std::cout << "B" << std::endl;
		} catch (...) {
			try {
				static_cast<void>(dynamic_cast<C &>(p));
				std::cout << "C" << std::endl;
			} catch (...) {
				std::cout << "ERROR" << std::endl;
			}
		}
	}
}

Base	*generate(void)
{
	std::srand(static_cast<unsigned>(std::time(0)));
	int	ran = std::rand() % 3;

	// std::cout << "randomly generated number: " << ran << std::endl;

	if (ran == 0)
		return (new A);
	else if (ran == 1)
		return (new B);
	else
		return (new C);
}

int	main(void)
{
	Base	*random = generate();
	identify(random);
	identify(*random);
	delete random;
}
