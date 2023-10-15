/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterParser.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:41:43 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/13 16:17:28 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* Parser */

void	ScalarConverter::scalarConverter(std::string input)
{
	if (input.length() == 0) // throw exception for empty input
		throw InvalidInputException();
	trimWhitespaces(input);
	parser(input);
	switchConverter();
}

void	ScalarConverter::trimWhitespaces(std::string &input)
{
	input.erase(0, input.find_first_not_of(WHITESPACES)); // trim leading white space
	input.erase(input.find_last_not_of(WHITESPACES) + 1); // trim trailing white space
}

void	ScalarConverter::parser(std::string input)
{
	if (isPseudoLiteral(input) || isChar(input)) // parse valid non-numeric input
		return ;
	_strInput = input;
	_type = catchNumericDataType(); // check invalidity and get data type of numeric input
	parseNumericData(); // parse the numeric data
}

bool	ScalarConverter::isPseudoLiteral(std::string const input)
{
	if (input == "-inff" || input == "inff" || input == "+inff" || input == "nanf" \
	|| input == "-inf" || input == "inf" || input == "+inf" || input == "nan")
	{
		_strInput = input;
		_type = PLITERAL;
		cout << ORANGE << "The parsed pseudo literal is: [" << input << "]" << RESET << endl << endl;
		return (true);
	}
	return (false);
}

bool	ScalarConverter::isChar(std::string const input)
{
	if (input.length() == 0) // whitespaces trimmed
		_data.charValue = ' ';
	else if (input.length() == 1 && !std::isdigit(input[0])) // a single char
		_data.charValue = input[0];
	else
		return (false);
	_type = CHAR;
	cout << ORANGE << "The parsed char is: [" << _data.charValue << "]" << RESET << endl << endl;
	return (true);
}

eType	ScalarConverter::catchNumericDataType(void)
{
	size_t	i = (_strInput[0] == '+' || _strInput[0] == '-');

	while (std::isdigit(_strInput[i]))
		i++;
	if (i == _strInput.length())
		return (INT);
	else if (_strInput[i++] != '.')
		return (ERROR);
	while (std::isdigit(_strInput[i]))
		i++;
	if (i == _strInput.length())
		return (DOUBLE);
	else if (_strInput[i++] == 'f' && i == _strInput.length())
		return (FLOAT);
	return (ERROR);
}

void	ScalarConverter::parseNumericData(void)
{
	switch (_type)
	{
	    case INT:
            _data.intValue = std::stoi(_strInput); // these functions throw an exception when under-/overflow happends
			cout << PINK << "The converted integer is: [" << _data.intValue << "]" << RESET << endl << endl;
            break;
        case FLOAT:
            _data.floatValue = std::stof(_strInput);
			cout << PINK << "The converted float is: [" << std::fixed << _data.floatValue << "f]" << RESET << endl << endl;
            break;
        case DOUBLE:
		    _data.doubleValue = std::stod(_strInput);
			cout << PINK << "The converted double is: [" << std::fixed << _data.doubleValue << "]" << RESET << endl << endl;
            break;
        default:
            throw InvalidInputException();
            break;
	}
}

const char	*ScalarConverter::InvalidInputException::what(void) const throw() {
    return ("\x1B[38;2;224;224;224mthe input is invalid\x1B[0m");
}