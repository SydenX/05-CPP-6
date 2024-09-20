
#include "ScalarConverter.hpp"
#include <sstream>
#include <cmath>
#include <iomanip>

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

void printChar(double d){
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "char: ";
	int i = static_cast<int>(std::round(d));
	 if (i < 32 || i > 126)
		std::cout << "Non displayable" << std::endl;
	else {
		std::cout << '\'' << static_cast<char>(i) << '\'' << std::endl;
	}
}

void printInt(double d){
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "int: ";
	 if ((d) > std::numeric_limits<int>::max() || (d) < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else {
		int i = static_cast<int>(std::round(d));
		std::cout << i << std::endl;
	}
}

void printFloat(double d){
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: ";
	if (std::abs(d) > std::numeric_limits<float>::max())
		std::cout << "impossible" << std::endl;
	else {
		float f = static_cast<float>(d);
		std::cout << f << "f" << std::endl;
	}
}

void printDouble(double d){
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: ";
	if (std::abs(d) > std::numeric_limits<double>::max())
		std::cout << "impossible" << std::endl;
	else {
		std::cout << d << std::endl;
	}
}

int checkStr(std::string &str){
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
		return -1;
	if (str[0] < 32 || str[0] > 126)
		return 1;
	if (str[0] == '.')
		return 8;
	int hasPoint = 0;
	for (unsigned long i = 1; i < (unsigned long)str.length(); i++){
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
		if (hasPoint > 1 || (str[i] == '.' && i == str.length() - 1))
			return 7;
	}
	return 0;
}

std::string charToInt(std::string in){
	int i = static_cast<int>(in[0]);
	std::ostringstream s; 
	s << i;
	return s.str();
}

void ScalarConverter::convert(std::string in){
	if (checkStr(in) != 0){
		if (checkStr(in) == -1){
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			if (in == "nan" || in == "+inf" || in == "-inf"){
				std::cout << "float: " << (in) << "f" << std::endl;
				std::cout << "double: " << (in) << std::endl;
			} else {
				std::cout << "float: " << (in) << std::endl;
				in[in.length() - 1] = 3;
				std::cout << "double: " << (in) << std::endl;
			}
			return;
		}
		std::cout << "Argument not a comptatible literal." << std::endl;
		return;
	}
	if (in.length() == 1 && in[0] >= 32 && in[0] <= 126 && (in[0] < '0' || in[0] > '9'))
		in = charToInt(in);
	double d = static_cast<double>(std::strtod(in.c_str(), NULL));
	printChar(d);
	printInt(d);
	printFloat(d);
	printDouble(d);
};
