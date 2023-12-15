#include "Parser.hpp"

bool	Parser::isValidInput(char **input)
{
	if (input == NULL || *input == NULL)
		return (false);

	long int num;
	char *endPtr;

	while (*input != NULL)
	{
		num = strtol(*input, &endPtr, 10);
		if (num <= 0 || num > INT_MAX || *endPtr != '\0')
			return (false);
		++input;
	}
	return (true);
}
