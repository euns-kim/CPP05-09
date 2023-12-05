#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include "Parser.hpp"

# define DATA "data.csv"
# define DB std::map<time_t, float>

namespace Database
{
	DB initDatabase(void);
}

class BitcoinExchange
{

	private:
		static DB _db;

		static int errorPrinter(std::string msg);
		
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &op);
		~BitcoinExchange(void);

	public:
		static int btc(std::string inputFile);

};

\
#endif