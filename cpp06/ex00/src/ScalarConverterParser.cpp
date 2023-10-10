/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterParser.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:41:43 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/10 17:54:22 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* Parser */

void	ScalarConverter::scalarConverter(std::string input)
{
	trimWhitespaces(input);
	if (input.length() == 0) // throw exception for empty input
		throw InvalidInputException();
	parser(input);
}

void	ScalarConverter::trimWhitespaces(std::string &input)
{
	input.erase(0, input.find_first_not_of(WHITESPACES)); // trim leading white space
	input.erase(input.find_first_not_of(WHITESPACES) + 1); // trim trailing white space
}

void	ScalarConverter::parser(std::string input)
{
	if (handlePseudoLiteral(input) || isChar(input)) // parse valid non-numeric input
		return ;
	//  checkInvalidCharacter(input); // filter once some invalid inputs
	_strInput = input;
	catchNumericDataType(); // get data type of numeric input
}

bool	ScalarConverter::handlePseudoLiteral(std::string const input)
{
	if (input == "-inff" || input == "inff" || input == "+inff" || input == "nanf" \
	|| input == "-inf" || input == "inf" || input == "+inf" || input == "nan")
	{
		_strInput = input;
		_type = PLITERAL;
		return (true);
	}
	return (false);
}

bool	ScalarConverter::isChar(std::string const input)
{
	if (input.length() == 1 && !std::isdigit(input[0]))
	{
		_strInput = input;
		_type = PLITERAL;
		return (true);
	}
	return (false);
}

// void	ScalarConverter::checkInvalidCharacter(std::string input)
// {
// 	// check if the str only contains valid characters
// 	std::string	allowedChars = "0123456789+-.f";
// 	size_t		foundPos = input.find_first_not_of(allowedChars);
// 	if (foundPos != std::string::npos)
// 		throw InvalidInputException();

// 	// only one sign char at the beginning of the str is allowed
// 	std::string	signs = "+-";
// 	size_t		signPos = input.find_first_of("+-");
// 	if (signPos != std::string::npos && signPos != 0 \
// 	&& (input.substr(1).find_first_of("+-") != std::string::npos))
// 		throw InvalidInputException();
// }

void	ScalarConverter::catchNumericDataType(void)
{
	std::istringstream	inputStream(_strInput);

	if (_strInput.find_first_of("f") != std::string::npos && inputStream >> _data.floatValue)
		_type = FLOAT;
	else if (_strInput.find_first_of(".") != std::string::npos && inputStream >> _data.doubleValue)
		_type = DOUBLE;
	else if (inputStream >> _data.intValue)
		_type = INT;
	else
		throw InvalidInputException();
}

const char	*ScalarConverter::InvalidInputException::what(void) const throw() {
    return ("\x1B[38;2;224;224;224mthe input is invalid\x1B[0m");
}
