
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>

class ScalarConverter {
	private:
		ScalarConverter();
		~ScalarConverter();
	public:
		ScalarConverter(ScalarConverter const &scalarconverter);
		ScalarConverter& 	operator=(ScalarConverter const&);
		static void convert(std::string in);
		static bool is_int(std::string);
		static bool is_float(std::string s);
		static bool is_numeric (std::string const & str);
};

#endif
