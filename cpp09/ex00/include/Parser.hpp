#ifndef PARSER_HPP
# define PARSER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <limits>

# define WHITESPACES " \t\v\f\r\n"

using std::cout;
using std::cerr;
using std::endl;

namespace Parser
{
	int errorPrinter(std::string const &msg);
	bool isDate(std::string &date);
	time_t makeTime(std::string const &date);
	void trimWhitespaces(std::string &input);
	float readFloatValue(std::string &number);
};

#endif