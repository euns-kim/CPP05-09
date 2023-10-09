/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterOrthodox.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:31:21 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/09 16:40:14 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* Orthodox Canonical Form */

ScalarConverter::ScalarConverter(void)
{
	// std::cout << PEACH << "[ScalarConverter] Default constructor called" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void) copy;
	// std::cout << PEACH << "[ScalarConverter] Copy constructor called" << RESET << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &op)
{
	(void) op;
	// std::cout << PEACH << "[ScalarConverter] Copy assignment operator called" << RESET << std::endl;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	// std::cout << PEACH << "[ScalarConverter] Destructor called" << RESET << std::endl;
}
