
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>

class ScalarConverter {
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter const &scalarconverter);
		ScalarConverter& 	operator=(ScalarConverter const&);
	public:
		static void convert(std::string in);
};

#endif
