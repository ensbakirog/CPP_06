#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
		return(std::cerr << ARG_ERR << std::endl, 1);

	ScalarConverter::convert(argv[1]);

	return 0;
}