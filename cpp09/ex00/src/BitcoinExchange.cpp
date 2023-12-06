#include "BitcoinExchange.hpp"

/* DB initiation */

DB BitcoinExchange::_db = Database::initDatabase();

/* Static functions */

int BitcoinExchange::btc(std::string inputFile)
{
	if (_db.empty())
		return (Parser::errorPrinter("database is empty"));
	if (inputFile.empty())
		return (Parser::errorPrinter("input filename is unknown"));

	std::ifstream input(inputFile);

	if (!input.is_open())
		return (Parser::errorPrinter("input file could not be opend"));

	std::string line;

	getline(input, line);
	if (input.eof())
		return (Parser::errorPrinter("input file is empty"));
	if (input.bad())
		return (Parser::errorPrinter("stream error while reading input file"));
	if (line.compare("date | value") != 0)
		return (Parser::errorPrinter("wrong input detected"));

	while (getline(input, line))
	{
		size_t pos = line.find('|');
		if (pos == std::string::npos)
			Parser::errorPrinter("bad input => [" + line + "]");
		else
		{
			std::string dateStr = line.substr(0, pos);
			std::string	valueStr = line.substr(pos + 1);

			handleErrorAndCalculate(dateStr, valueStr);
		}
	}
	if (input.bad())
		return (Parser::errorPrinter("stream error while reading input file"));
	input.close();
	return (0);
}

void	BitcoinExchange::handleErrorAndCalculate(std::string& dateStr, std::string& valueStr)
{
	if (!Parser::isDate(dateStr))
	{
		Parser::errorPrinter("bad date => [" + dateStr + "]");
		return ;
	}

	float parsed = Parser::readFloatValue(valueStr);
	if (parsed == -3)
		Parser::errorPrinter("bad value => [" + valueStr + "]");
	else if (parsed == -2)
		Parser::errorPrinter("not a positive number => [" + valueStr + "]");
	else if (parsed == -1 || parsed > 1000)
		Parser::errorPrinter("too large a number => [" + valueStr + "]");
	else
	{
		parsed = BTCcalculator(dateStr, parsed);
		if (parsed == -1)
			Parser::errorPrinter("no exchange rate found for this date => [" + dateStr + "]");
		else
			cout << dateStr << " => " << valueStr << " = " << parsed << endl;
	}
}

float	BitcoinExchange::BTCcalculator(std::string dateStr, float parsed)
{
	time_t key = Parser::makeTime(dateStr);

	DB::iterator it = _db.find(key);
	if (it != _db.end())
		return (it->second * parsed); // takes the value of the key
	it = _db.upper_bound(key);
	if (it == _db.end())
		return (-1); // no data for this date
	return (it->second * parsed); // takes the value of the upper bound key
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
