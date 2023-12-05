#ifndef DATABASE_HPP
# define DATABASE_HPP

# define DATA "data.csv"
# define DB std::map<time_t, float>
# define PAIR std::pair<time_t, float>

# include <map>
# include <fstream>
# include "Parser.hpp"

typedef enum e_DB_exit_code
{
	DB_SUCCESS,
	DB_OPEN_ERROR,
	DB_EMPTY_DATA,
	DB_FSTREAM_ERROR,
	DB_WRONG_DATA
}	DB_exit_code;

namespace Database
{
	DB emptyMap();
	DB initDatabase(void);
	std::pair<DB_exit_code, DB> parseDatabase(void);
	void errorPrinter(DB_exit_code error);
}

#endif