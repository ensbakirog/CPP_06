#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

	#include <string>

	#define ARG_ERR "Error: ./program <arg>"

	class ScalarConverter
	{
		private:
			ScalarConverter();
			ScalarConverter(const ScalarConverter& other);
			ScalarConverter& operator=(const ScalarConverter& other);
			~ScalarConverter();
		public:
			static void convert(const std::string& str);
	};

#endif