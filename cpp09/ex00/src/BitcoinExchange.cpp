#include "BitcoinExchange.hpp"

/* DB initiation */

DB BitcoinExchange::_db = Database::initDatabase();

/* Static functions */

int BitcoinExchange::btc(std::string inputFile)
{
	if (_db.empty())
		return (Parser::errorPrinter("[BTC] database is empty"));
	if (inputFile.empty())
		return (Parser::errorPrinter("[BTC] input filename is unknown"));
}

/* Orthodox Canonical Form */

BitcoinExchange::BitcoinExchange(void)
{
	// std::cout << "[BitcoinExchange] Default constructor called" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	(void) copy;
	// std::cout << "[BitcoinExchange] Copy constructor called" << RESET << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &op)
{
	(void) op;
	// std::cout << "[BitcoinExchange] Copy assignment operator called" << RESET << std::endl;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	// std::cout << "[BitcoinExchange] Destructor called" << RESET << std::endl;
}
