/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:17:10 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/15 18:57:20 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <chrono>
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
		A	&a = dynamic_cast<A &>(p);
		(void) a;
		std::cout << "A" << std::endl;
	} catch (...) {
		try {
			B	&b = dynamic_cast<B &>(p);
			(void) b;
			std::cout << "B" << std::endl;
		} catch (...) {
			try {
				C	&c = dynamic_cast<C &>(p);
				(void) c;
				std::cout << "C" << std::endl;
			} catch (...) {
				std::cout << "ERROR" << std::endl;
			}
		}
	}
}

Base	*generate(void)
{
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
	std::srand(std::time(0));
	
	Base	*random = generate();
	identify(random);
	identify(*random);
	delete random;

	Base	*random2 = generate();
	identify(random2);
	identify(*random2);
	delete random2;

	Base	*random3 = generate();
	identify(random3);
	identify(*random3);
	delete random3;
}
