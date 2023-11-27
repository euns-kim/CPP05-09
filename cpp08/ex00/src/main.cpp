/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:22:49 by eunskim           #+#    #+#             */
/*   Updated: 2023/11/27 15:59:54 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"

template <typename T>
T	containerMaker(unsigned int size)
{
	T	container;

	unsigned int i = 0;
	for (; i < size; i++)
	{
		container.push_back(i);
	}
	return (container);
}

int main(void)
{
	{
		std::vector<int> vec = containerMaker< std::vector<int> >(100);
		std::vector<int>::iterator itr;

		try {
			itr = easyfind(vec, 30);
			std::cout << *itr << " is in the container" << std::endl;
		} catch (const std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}		
	}
	{
		std::deque<int> que = containerMaker< std::deque<int> >(50);
		std::deque<int>::iterator itr;

		try {
			itr = easyfind(que, 45);
			std::cout << *itr << " is in the container" << std::endl;
		} catch (const std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	{
		std::list<int> lst = containerMaker< std::list<int> >(103);
		std::list<int>::iterator itr;

		try {
			itr = easyfind(lst, 0);
			std::cout << *itr << " is in the container" << std::endl;
		} catch (const std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
}
