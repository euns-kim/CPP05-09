/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterParser.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:41:43 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/09 19:42:12 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* Parser */

void	ScalarConverter::scalarConverter(std::string input)
{
	trimWhitespaces(input);
	if (input.length() == 0)
		throw InvalidInputException();
	parser(input);
}

void	ScalarConverter::trimWhitespaces(std::string &input)
{
	input.erase(0, input.find_first_not_of(WHITESPACES));
	input.erase(input.find_first_not_of(WHITESPACES) + 1);
}

void	ScalarConverter::parser(std::string input)
{
	if (handlePseudoLiteral(input) || isChar(input)) // parse valid non-numeral input
		return ;
	checkInvalidCharacter(input); // filter once some invalid inputs
	catchDataType(input); // get data type of numeral input while checking final validity
}

bool	ScalarConverter::handlePseudoLiteral(std::string const input)
{
	if (input == "-inff" || input == "+inff" || input == "nanf" \
	|| input == "-inf" || input == "+inf" || input == "nan")
	{
		_strInput = input;
		_type = PLITERAL;
		return (true);
	}
	return (false);
}

bool	ScalarConverter::isChar(std::string const input)
{
	if (input.length() == 1 && std::isalpha(input[0]))
	{
		_strInput = input;
		_type = PLITERAL;
		return (true);
	}
	return (false);
}

void	ScalarConverter::checkInvalidCharacter(std::string input)
{
	// check if the str only contains valid characters
	std::string	allowedChars = "0123456789+-.f";
	size_t		foundPos = input.find_first_not_of(allowedChars);
	if (foundPos != std::string::npos)
		throw InvalidInputException();

	// only one sign char at the beginning of the str is allowed
	std::string	signs = "+-";
	size_t		signPos = input.find_first_of("+-");
	if (signPos != std::string::npos && signPos != 0 \
	&& (input.substr(1).find_first_of("+-") != std::string::npos))
		throw InvalidInputException();
}

void	ScalarConverter::catchDataType(std::string input)
{
	// size_t	pointPos = input.find_first_of(".");
	// if (pointPos == std::string::npos)
}

const char	*ScalarConverter::InvalidInputException::what(void) const throw() {
    return ("\x1B[38;2;224;224;224mthe input is invalid\x1B[0m");
}
