#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <ctime>
# include "Parser.hpp"
# include "Database.hpp"

class BitcoinExchange
{

	private:
		static DB _db;
		
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &op);
		~BitcoinExchange(void);

	public:
		static int btc(std::string inputFile);

};

\
#endif