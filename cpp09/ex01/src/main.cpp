#include "Span.hpp"

int main(void)
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		Span sp = Span(5);
		sp.addNumber(0);
		sp.addNumber(-23);
		sp.addNumber(-10007);
		sp.addNumber(-9);
		sp.addNumber(32);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		Span sp(10);
		sp.fillContainerRandom();
		sp.printContainer();

		// try {
		// 	sp.addNumber(10);
		// } catch (const std::exception &e) {
		// 	std::cerr << "Exception: " << e.what() << std::endl;
		// }

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		sp.printContainer();
	}
	{
		Span sp(10000);
		std::vector<int> vec;
		for (unsigned int i = 0; i < 10000; i++)
			vec.push_back(i);

		sp.fillContainerRange(vec.begin(), vec.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		Span sp(10000);
		std::vector<int> vec;
		for (unsigned int i = 0; i < 10000; i++)
			vec.push_back(i * 2 - 5000);

		sp.fillContainerRange(vec.begin(), vec.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		Span sp(1000);
		std::vector<int> vec;
		for (unsigned int i = 0; i < 10000; i++)
			vec.push_back(i * 2 - 5000);

		try {
			sp.fillContainerRange(vec.begin(), vec.end());
		} catch (const std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		try {
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
}