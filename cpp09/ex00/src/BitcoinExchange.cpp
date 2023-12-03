#include "BitcoinExchange.hpp"

/* Orthodox Canonical Form */

BitcoinExchange::BitcoinExchange(void) : _inputFile(NULL)
{
	// std::cout << "[BitcoinExchange] Default constructor called" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string inputFile) : _inputFile(inputFile)
{
	// std::cout << "[BitcoinExchange] String constructor called" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
: _database(std::map<time_t, float>(copy._database)), _inputFile(copy._inputFile)
{
	// std::cout << "[BitcoinExchange] Copy constructor called" << RESET << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &op)
{
	if (this != &op)
	{
		this->_inputFile = op._inputFile;
		this->_database = std::map<time_t, float>(op._database);
	}
	// std::cout << "[BitcoinExchange] Copy assignment operator called" << RESET << std::endl;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	// std::cout << "[BitcoinExchange] Destructor called" << RESET << std::endl;
}

/* Method functions */

time_t BitcoinExchange::makeTime(std::string date)
{
	int year = atoi(date.c_str());
	int month = atoi(date.c_str() + 5);
	int day = atoi(date.c_str() + 8);

	// if (year < 2009 || year > 2022 \
	// || month < 1 || month > 12 \
	// || day < 1 || day > 31)

	tm timeinfo;

	timeinfo.tm_year = year - 1900;
	timeinfo.tm_mon = month - 1;
	timeinfo.tm_mday = day;
	timeinfo.tm_hour = 0;
	timeinfo.tm_min = 0;
	timeinfo.tm_sec = 0;

	return (mktime(&timeinfo));
}
