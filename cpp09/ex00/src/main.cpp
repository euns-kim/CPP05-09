#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: [PROGRAM] a second database is needed as input" << std::endl;
		return (1);
	}
	return (BitcoinExchange::btc(static_cast<std::string>(argv[1])));
}
