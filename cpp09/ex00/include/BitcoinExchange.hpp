#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <ctime>
# include "Database.hpp"

class BitcoinExchange
{

	private:
		static DB _db;

		static float BTCcalculator(std::string dateStr, float parsed);

		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &op);
		~BitcoinExchange(void);

	public:
		static int btc(std::string inputFile);

};

#endif