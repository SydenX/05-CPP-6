
#include "ScalarConverter.hpp"
#include <sstream>
#include <cmath>

//Constructor
ScalarConverter::ScalarConverter() {
}

//Destructor
ScalarConverter::~ScalarConverter() {
}

//Copy-Constructor
ScalarConverter::ScalarConverter(ScalarConverter const &scalarconverter) {
	*this = scalarconverter;
}

//Copy-Assignment Operator Overload
ScalarConverter&	ScalarConverter::operator=(ScalarConverter const &scalarconverter){
	(void) scalarconverter;
	return *this;
}

std::string getChar(std::string &s){
	std::string str;
	double i = std::strtol(s.c_str(), NULL, 10);
	if (s == "nan")
		str = "Impossible..";
	else if (i < 32 || i > 126)
		str = "Not displayable";
	else {
		str += '\'';
		str += i;
		str += '\'';
	}
	return str;
}

std::string getInt(std::string &s){
	std::string str;
	double d = std::strtol(s.c_str(), NULL, 10);
	if (s == "nan")
		str = "Impossible..";
	else if (std::abs(d) > std::numeric_limits<int>::max())
		str = "Impossible..";
	else {
		std::ostringstream s; 
		s << d; 
		str = s.str();
	}
	return str;
}

std::string getFloat(std::string &s){
	double d = std::strtof(s.c_str(), NULL);
	std::string str;
	if (std::abs(d) > std::numeric_limits<float>::max())
		str = "Impossible..";
	else {
		std::ostringstream s; 
		s << std::defaultfloat << d;
		str = s.str() + "f";
		if (!(str.find(".") != std::string::npos) && str != "nanf")
			str += ".0";
	}
	return str;
}

std::string getDouble(std::string &s){
	double d = std::strtod(s.c_str(), NULL);
	std::string str;
	if (std::abs(d) > std::numeric_limits<double>::max())
		str = "Impossible..";
	else {
		std::ostringstream s; 
		s << std::defaultfloat << d;
		str = s.str();
		if (!(str.find(".") != std::string::npos) && str != "nan")
			str += ".0";
	}
	return str;
}

void ScalarConverter::convert(std::string in){
	// double t = 1.8;
	// std::cout << static_cast<int>(round(t)) << std::endl;
	std::cout << "Char   is :" << getChar(in) << std::endl;
	std::cout << "Int    is :" << getInt(in) << std::endl;
	std::cout << "Float  is :" << getFloat(in) << std::endl;
	std::cout << "Double is :" << getDouble(in) << std::endl;
	std::cout << std::endl;
};
