#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <string>

class BitcoinExchange
{

	private:
		std::map<time_t, float> _database;
		std::string	_inputFile;

	public:
		BitcoinExchange(void);
		BitcoinExchange(std::string inputFile);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &op);
		~BitcoinExchange(void);

		time_t makeTime(std::string date);
};

#endif