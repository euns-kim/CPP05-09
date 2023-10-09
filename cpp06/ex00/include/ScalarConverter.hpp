/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:54:32 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/09 19:44:45 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <exception>
# include <string>

# define RESET	"\x1B[0m"
# define PINK	"\x1B[38;2;255;204;229m"
# define ORANGE	"\x1B[38;2;255;178;102m"
# define PEACH	"\x1B[38;2;255;153;153m"
# define LIME	"\x1B[38;2;204;255;204m"
# define LEMON	"\x1B[38;2;229;229;204m"
# define SKY	"\x1B[38;2;204;229;255m"
# define ICE	"\x1B[38;2;204;255;255m"
# define HERB	"\x1B[38;2;204;255;229m"
# define GREY	"\x1B[38;2;224;224;224m"

# define WHITESPACES " \t\v\f\r\n"

using std::cout;
using std::cerr;
using std::endl;

class ScalarConverter
{

	private:
		static long double	_input;
		static std::string	_strInput;

		enum eType {
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			PLITERAL,
			ERROR
		};

		static eType	_type;

		union uData {
			int intValue;
        	double doubleValue;
        	float floatValue;
        	char charValue;
		};

		static uData	_data;

		/* Orthodox Canonical Form */
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &op);
		~ScalarConverter(void);

		/* Parser */
		static void	parser(std::string input);
		static void	trimWhitespaces(std::string &input);
		static bool	handlePseudoLiteral(std::string const input);
		static bool	isChar(std::string const input);
		static void	checkInvalidCharacter(std::string input);
		static void	catchDataType(std::string input);

		/* Converter */
		static void	convertToChar(void);
		static void	convertToInt(void);
		static void	convertToFloat(void);
		static void	convertToDouble(void);

		/* Printer */
		static void	printCharValue(void);
		static void	printIntValue(void);
		static void	printFloatValue(void);
		static void	printDoubleValue(void);

	public:
		static void	scalarConverter(std::string input);

		/* Excepton */
		class InvalidInputException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

};

#endif