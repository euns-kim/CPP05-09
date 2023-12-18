#include "Database.hpp"

/* DB initiation */

DB Database::emptyMap(void)
{
	return (DB());
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
	DB tmpMap;
	PAIR tmpPair;
	std::ifstream data(DATA);

	if (!data.is_open())
		return (std::make_pair(DB_OPEN_ERROR, tmpMap));

	char delim[2] = {'\n', ','};
	bool button = true;
	std::string	line;

	getline(data, line);
	if (data.eof())
		return (std::make_pair(DB_EMPTY_DATA, tmpMap));
	if (data.bad())
		return (std::make_pair(DB_FSTREAM_ERROR, tmpMap));
	if (line.compare("date,exchange_rate") != 0)
		return (std::make_pair(DB_WRONG_DATA, tmpMap));

	while (getline(data, line, delim[button]))
	{
		if (button == true)
		{
			if (Parser::isDate(line))
				tmpPair.first = Parser::makeTime(line);
			else
				return (std::make_pair(DB_WRONG_DATA, emptyMap()));
		}
		else
		{
			tmpPair.second = Parser::readFloatValue(line);
			if (tmpPair.second < 0)
				return (std::make_pair(DB_WRONG_DATA, emptyMap()));
			tmpMap.insert(tmpPair);
		}
		button = !button;
	}
	if (data.bad())
		return (std::make_pair(DB_FSTREAM_ERROR, emptyMap()));
	data.close();
	return (std::make_pair(DB_SUCCESS, tmpMap));
}

void Database::errorPrinter(DB_exit_code error)
{
	cout << "Error: [DB] ";
    switch (error)
	{
		case DB_OPEN_ERROR:
			cout << "data file could not be opened" << endl;
			break;
		case DB_EMPTY_DATA:
			cout << "data file is empty" << endl;
			break;
		case DB_FSTREAM_ERROR:
			cout << "stream error while reading data file" << endl;
			break;
		case DB_WRONG_DATA:
			cout << "wrong data detected" << endl;
			break;
		default:
			cout << "something is wrong with DB parsing" << endl;
    }
}