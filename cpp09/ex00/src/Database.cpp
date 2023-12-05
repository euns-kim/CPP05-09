#include "Database.hpp"

/* DB initiation */

DB Database::emptyMap()
{
    return DB();
}

DB Database::initDatabase(void)
{
	std::pair<DB_exit_code, DB> ret = Database::parseDatabase();

	if (ret.first != 0)
		Database::errorPrinter(ret.first);
	return (ret.second);
}

std::pair<DB_exit_code, DB> Database::parseDatabase(void)
{
	std::ifstream data(DATA);

	if (!data.is_open())
		return (std::make_pair(DB_OPEN_ERROR, emptyMap()));
	if (data.eof())
		return (std::make_pair(DB_EMPTY_DATA, emptyMap()));
	if (data.fail() || !data.good())
		return (std::make_pair(DB_FSTREAM_ERROR, emptyMap()));

	DB tmpDB;
	PAIR tmpPair;

	char delim[2] = {'\n', ','};
	bool button = true;
	std::string	line;

	getline(data, line);
	if (line.compare("date,exchange_rate") != 0)
		return (std::make_pair(DB_WRONG_DATA, emptyMap()));

	while (getline(data, line, delim[button]))
	{
		Parser::trimWhitespaces(line);
		if (button == true)
		{
			if (Parser::isDate(line))
				tmpPair.first = Parser::makeTime(line);
			else
				return (std::make_pair(DB_WRONG_DATA, emptyMap()));
		}
		else
		{
			// check exchange rate;
			// add it to pair
			// add the pair to db;
		}
		button = !button;
	}
	data.close();
}

void Database::errorPrinter(DB_exit_code error)
{
    switch (error)
	{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:
    }
}