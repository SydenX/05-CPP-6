
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
	if (s == "nan" || s == "+inf" || s == "-inf" || s == "+inff" || s == "-inff")
		str = "impossible";
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
	if (s == "nan" || s == "nanf" || s == "+inf" || s == "-inf" || s == "+inff" || s == "-inff")
		str = "impossible";
	else if (std::abs(d) > std::numeric_limits<int>::max())
		str = "impossible";
	else {
		std::ostringstream s; 
		s << d; 
		str = s.str();
	}
	return str;
}

std::string getFloat(std::string &s){
	std::string str;
	if (s == "+inf" || s == "-inf" || s == "+inff" || s == "-inff")
		return s;
	double d = std::strtof(s.c_str(), NULL);
	if (std::abs(d) > std::numeric_limits<float>::max())
		str = "impossible";
	else {
		std::ostringstream s; 
		s << std::defaultfloat << d;
		str += s.str();
		if (!(str.find(".") != std::string::npos) && str != "nan")
			str += ".0";
		str += "f";
	}
	return str;
}

std::string getDouble(std::string &s){
	std::string str;
	if (s == "+inf" || s == "-inf" || s == "+inff" || s == "-inff")
		return s;
	double d = std::strtod(s.c_str(), NULL);
	if (std::abs(d) > std::numeric_limits<double>::max())
		str = "impossible";
	else {
		std::ostringstream s; 
		s << std::defaultfloat << d;
		str = s.str();
		if (!(str.find(".") != std::string::npos) && str != "nan")
			str += ".0";
	}
	return str;
}

int checkStr(std::string &str){
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
		return 0;
	if (str[0] < 32 || str[0] > 126)
		return 1;
	int hasPoint = 0;
	for (int i = 1; i < (long long)str.length(); i++){
		if (str[i - 1] < '0' || str[i - 1] > '9'){
			if (str[i - 1] != '.' && str[i - 1] != '-')
				return 2;
			else if (str[i] < '0' || str[i] > '9')
				return 3;
		}
		else if ((str[i] < '0' || str[i] > '9') && str[i] != 'f' && str[i] != '.')
			return 4;
		if (str[i] == '.' && (str[i - 1] < '0' || str[i - 1] > '9'))
			return 5;
		if (str[i] == '-')
			return 6;
		if (str[i] == '.')
			hasPoint++;
		if (hasPoint > 1)
			return 7;
	}
	return 0;
}

std::string charToInt(std::string in){
	int i = in[0];
	std::ostringstream s; 
	s << i;
	return s.str();
}

void ScalarConverter::convert(std::string in){
	if (checkStr(in) != 0){
		std::cout << "Argument not a comptatible literal." << std::endl;
		return;
	}
	if (in.length() == 1 && in[0] >= 32 && in[0] <= 126 && (in[0] < '0' || in[0] > '9'))
		in = charToInt(in);
	std::cout << "char: " << getChar(in) << std::endl;
	std::cout << "int: " << getInt(in) << std::endl;
	std::cout << "float: " << getFloat(in) << std::endl;
	std::cout << "double: " << getDouble(in) << std::endl;
};
