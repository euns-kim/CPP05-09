#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Error: a second database is needed as input" << std::endl;

	return (BitcoinExchange::btc(static_cast<std::string>(argv[1])));
}
