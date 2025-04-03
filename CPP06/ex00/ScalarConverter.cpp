#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter(std::string str) : _str(str) {}

ScalarConverter::~ScalarConverter() {}

{
	private:
		/* data */
	public:
		ScalarConverter(std::string string);
		ScalarConverter(const ScalarConverter& copy);
		~ScalarConverter();
	
		ScalarConverter& operator=(const ScalarConverter& src);
		void	convert(std::string string);
	};
	