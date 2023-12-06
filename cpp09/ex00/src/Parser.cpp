#include "Parser.hpp"

/* Helper functions for parsing */

int Parser::errorPrinter(std::string msg)
{
	cerr << "Error: [BTC] " << msg << endl;
	return (EXIT_FAILURE);
}

bool Parser::isDate(std::string &date)
{
	trimWhitespaces(date);
	if (date.length() != 10)
		return (false);

	int year, month, day;
	char delimiter1;
	char delimiter2;
	std::istringstream ss(date);

	ss >> year >> delimiter1 >> month >> delimiter2 >> day;

	if (year < 2009 || year > 2022 \
	|| month < 1 || month > 12 || day < 1)
		return (false);

	if (ss.fail() || delimiter1 != '-' || delimiter2 != '-')
		return (false);

	int daysOfMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30 , 31, 30, 31};
	
	if (year % 4 == 0 && (year % 100 != 0 || year % 400))
		daysOfMonth[2] = 29; // leap year

	return (day <= daysOfMonth[month]);
}

time_t Parser::makeTime(std::string date)
{
	int year = atoi(date.c_str());
	int month = atoi(date.c_str() + 5);
	int day = atoi(date.c_str() + 8);

	tm timeinfo;

	timeinfo.tm_year = year - 1900;
	timeinfo.tm_mon = month - 1;
	timeinfo.tm_mday = day;
	timeinfo.tm_hour = 0;
	timeinfo.tm_min = 0;
	timeinfo.tm_sec = 0;

	return (mktime(&timeinfo));
}

void	Parser::trimWhitespaces(std::string &input)
{
	input.erase(0, input.find_first_not_of(WHITESPACES)); // trim leading white space
	input.erase(input.find_last_not_of(WHITESPACES) + 1); // trim trailing white space
}

float	Parser::readFloatValue(std::string &number)
{
	trimWhitespaces(number);
	const char *numPtr = number.c_str();
	char *endPtr;
	double value = strtod(numPtr, &endPtr);

	if (endPtr == numPtr || *endPtr != '\0')
		return (-3);
	if (value < 0)
		return (-2);
	if (value > static_cast<double>(FLT_MAX))
		return (-1);
	return (static_cast<double>(value));
}
 