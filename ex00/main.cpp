/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:12:19 by jtollena          #+#    #+#             */
/*   Updated: 2024/09/20 11:35:32 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <float.h>

int main(int argc, char **argv){
	if (argc != 2){
		std::cout << "1 argument only is required to use this converter." << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	// ScalarConverter::convert("123.456");
	// ScalarConverter::convert("-123.456f");
	// ScalarConverter::convert("89");
	// ScalarConverter::convert("nan");
	// ScalarConverter::convert("-inf");
	// ScalarConverter::convert("+inff");
	return 0;
}