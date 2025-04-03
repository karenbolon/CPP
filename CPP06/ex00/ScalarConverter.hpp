#pragma once
#include <string>


class ScalarConverter
{
private:
	std::string	_str;
public:
	ScalarConverter(std::string str);
	ScalarConverter(const ScalarConverter& copy);
	~ScalarConverter();

	ScalarConverter& operator=(const ScalarConverter& src);
	void	convert(std::string str);
};


