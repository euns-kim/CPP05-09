/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:53:59 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/09 18:22:28 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		cout << "Invalid argument" << endl \
		<< "Usage: ./ScalarConverter [a literal to convert as a string]" << endl;
	else
	{
		try {
			ScalarConverter::scalarConverter(argv[2]);
		} catch (std::exception &e) {
			cerr << "Program failed because " << e.what() << endl;
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}