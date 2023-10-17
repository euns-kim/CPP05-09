/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterConverter.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:53:35 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/17 16:59:16 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	ScalarConverter::convertCharValue(void)
{
	// print char
	if ((_data.charValue >= -128 && _data.charValue < 32) || _data.charValue == 127)
		cout << LEMON << "char: non displayable" << RESET << endl;
	else if (_data.charValue < -128 || _data.charValue > 127)
		cout << LEMON << "char: impossible" << RESET << endl;
	else
		cout << LEMON << "char: '" << _data.charValue << "'" << RESET << endl;

	// print int
	cout << LEMON << "int: " << static_cast<int>(_data.charValue) << RESET << endl;

	// print float
	cout << LEMON << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(_data.charValue) << "f" << RESET << endl;

	// print doulble
	cout << LEMON << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(_data.charValue) << RESET << endl;
}

void	ScalarConverter::convertIntValue(void)
{
	// print char
	if ((_data.intValue >= -128 && _data.intValue < 32) || _data.intValue == 127)
		cout << LEMON << "char: non displayable" << RESET << endl;
	else if (_data.intValue < -128 || _data.intValue > 127)
		cout << LEMON << "char: impossible" << RESET << endl;
	else
		cout << LEMON << "char: '" << static_cast<char>(_data.intValue) << "'" << RESET << endl;
	
	// print int
	cout << LEMON << "int: " << _data.intValue << RESET << endl;

	// print float
	cout << LEMON << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(_data.intValue) << "f" << RESET << endl;

	// print doulble
	cout << LEMON << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(_data.intValue) << RESET << endl;
}

void	ScalarConverter::convertFloatValue(void)
{
	// print char
	if ((_data.floatValue >= -128 && _data.floatValue < 32) || _data.floatValue == 127)
		cout << LEMON << "char: non displayable" << RESET << endl;
	else if (_data.floatValue < -128 || _data.floatValue > 127)
		cout << LEMON << "char: impossible" << RESET << endl;
	else
		cout << LEMON << "char: '" << static_cast<char>(_data.floatValue) << "'" << RESET << endl;

	// print int
	if (_data.floatValue < std::numeric_limits<int>::min() || _data.floatValue > std::numeric_limits<int>::max())
		cout << LEMON << "int: impossible" << RESET << endl;
	else
		cout << LEMON << "int: " << static_cast<int>(_data.floatValue) << RESET << endl;

	// print float
	cout << LEMON << "float: " << std::fixed << std::setprecision(1) << _data.floatValue << "f" << RESET << endl;

	// print doulble
	cout << LEMON << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(_data.floatValue) << RESET << endl;
}

void	ScalarConverter::convertDoubleValue(void)
{
	// print char
	if ((_data.doubleValue >= -128 && _data.doubleValue < 32) || _data.doubleValue == 127)
		cout << LEMON << "char: non displayable" << RESET << endl;
	else if (_data.doubleValue < -128 || _data.doubleValue > 127)
		cout << LEMON << "char: impossible" << RESET << endl;
	else
		cout << LEMON << "char: '" << static_cast<char>(_data.doubleValue) << "'" << RESET << endl;

	// print int
	if (_data.doubleValue < std::numeric_limits<int>::min() || _data.doubleValue > std::numeric_limits<int>::max())
		cout << LEMON << "int: impossible" << RESET << endl;
	else
		cout << LEMON << "int: " << static_cast<int>(_data.doubleValue) << RESET << endl;

	// print float
	if (_data.doubleValue < std::numeric_limits<float>::lowest() || _data.doubleValue > std::numeric_limits<float>::max())
		cout << LEMON << "float: impossible" << RESET << endl;
	else
		cout << LEMON << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(_data.doubleValue) << "f" << RESET << endl;

	// print doulble
	cout << LEMON << "double: " << std::fixed << std::setprecision(1) << _data.doubleValue << RESET << endl;
}

void	ScalarConverter::handlePseudoLiteral(void)
{
	cout << LEMON << "char: impossible" << endl \
	<< "int: impossible" << RESET << endl;

	size_t	i = (_strInput[0] == '+' || _strInput[0] == '-');
	if (_strInput.compare(i, 3, "inf") == 0)
	{
		cout << LEMON << "float: " << _strInput.substr(0, i + 3) << "f" << endl \
		<< "double: " << _strInput.substr(0, i + 3) << RESET << endl;
	}
	else if (_strInput.compare(0, 3, "nan") == 0)
	{
		cout << LEMON << "float: nanf" << endl \
		<< "double: nan" << RESET << endl;
	}
	else
		throw InvalidInputException();
}

void	ScalarConverter::switchConverter(void)
{
	switch (_type)
	{
		case PLITERAL:
			handlePseudoLiteral();
			break;
		case CHAR:
			convertCharValue();
			break;
		case INT:
			convertIntValue();
			break;
		case FLOAT:
			convertFloatValue();
			break;
		case DOUBLE:
			convertDoubleValue();
			break;
		default:
			throw InvalidInputException();
			break;
	}
}
