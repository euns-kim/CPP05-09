#include "BitcoinExchange.hpp"

/* DB initiation */

DB BitcoinExchange::_db = Database::initDatabase();

DB Database::initDatabase(void)
{

}

/* Static functions */

int BitcoinExchange::btc(std::string inputFile)
{
	if (_db.empty())
		return (errorPrinter("database is empty"));
	if (inputFile.empty())
		return (errorPrinter("input filename is unknown"));
}

int BitcoinExchange::errorPrinter(std::string msg)
{
	cout << "Error: " << msg << endl;
	return (EXIT_FAILURE);
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
