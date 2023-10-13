/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:54:32 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/13 15:50:46 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <exception>
# include <string>
# include <sstream>
# include <limits>
# include <iomanip>

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

/**
 * Static functions of the class belong to the class itself, not to an instance.
 * So it is possible to use those without creating an instance of the class.
 * Private static functions can be called only in a public static function of the same class.
 * Variables of the class below are also declared as static, so that it can be used without any instance.
 */

enum eType {
	ERROR,
	PLITERAL,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

union uData {
	int		intValue;
	double	doubleValue;
	float	floatValue;
	char	charValue;
};

class ScalarConverter
{

	private:
		static std::string	_strInput;
		static eType		_type;
		static uData		_data;

		/* Orthodox Canonical Form */
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &op);
		~ScalarConverter(void);

		/* Parser */
		static void		parser(std::string input);
		static void		trimWhitespaces(std::string &input);
		static bool		isPseudoLiteral(std::string const input);
		static bool		isChar(std::string const input);
		static eType	catchNumericDataType(void);
		static void		parseNumericData(void);

		/* Converter */
		static void	switchConverter(void);
		static void	handlePseudoLiteral(void);
		static void	convertCharValue(void);
		static void	convertIntValue(void);
		static void	convertFloatValue(void);
		static void	convertDoubleValue(void);

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