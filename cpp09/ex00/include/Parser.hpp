#ifndef PARSER_HPP
# define PARSER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <cfloat>

# define WHITESPACES " \t\v\f\r\n"

using std::cout;
using std::cerr;
using std::endl;

namespace Parser
{
	int errorPrinter(std::string msg);
	bool isDate(std::string &date);
	time_t makeTime(std::string date);
	void trimWhitespaces(std::string &input);
	float readFloatValue(std::string &number);
};

#endif