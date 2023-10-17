/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:44:54 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/17 16:55:42 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	int int_arr[] = {5, 4, 3, 2, 1};
	::iter(int_arr, 5, printT<int>);
	// ::iter(int_arr, 5, &printT);
	std::cout << std::endl;

	float float_arr[] = {1.3, 1.2, 1.1, 1.0, 0.9, 0.8};
	::iter(float_arr, 6, printT<float>);
	// ::iter(float_arr, 6, &printT);
	std::cout << std::endl;

	char char_arr[] = {'a', 'b', 'c'};
	::iter(char_arr, 3, printT<char>);
	// ::iter(char_arr, 3, &printT);
	std::cout << std::endl;

	std::string	str_arr[] = {"Hello", "World", "Hello"};
	::iter(str_arr, 3, printT<std::string>);
	// ::iter(str_arr, 3, &printT<std::string>);
}
