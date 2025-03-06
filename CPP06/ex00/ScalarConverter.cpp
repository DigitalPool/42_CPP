/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:54:58 by mac               #+#    #+#             */
/*   Updated: 2025/03/06 08:26:16 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cctype>
#include <cerrno>
#include <cmath>

static bool isPseudoLiteral(const std::string& str) {
	return (str == "nan" || str == "nanf" ||
			str == "+inf" || str == "-inf" ||
			str == "+inff" || str == "-inff");
}

static bool isQuotedCharLiteral(const std::string& str) {
	return (str.length() == 3 && str.front() == '\'' && str.back() == '\'');
}

void ScalarConverter::convert(const std::string& literal) {
	double dVal = 0.0;
	bool conversionError = false;

	if (literal.length() == 1 && !std::isdigit(literal[0])) {
		dVal = static_cast<double>(literal[0]);
	}

	else if (isQuotedCharLiteral(literal)) {
		dVal = static_cast<double>(literal[1]);
	}

	else if (isPseudoLiteral(literal)) {
		dVal = std::strtod(literal.c_str(), nullptr);
	}

	else {
		std::string numStr = literal;
		if (numStr.back() == 'f' && numStr.length() > 1)
			numStr = numStr.substr(0, numStr.size() - 1);

		char* end;
		errno = 0;
		dVal = std::strtod(numStr.c_str(), &end);
		if (errno != 0 || *end != '\0')
			conversionError = true;
	}

	std::cout << "char: ";
	if (conversionError || std::isnan(dVal)
		|| dVal < static_cast<double>(std::numeric_limits<char>::min())
		|| dVal > static_cast<double>(std::numeric_limits<char>::max()))
		std::cout << "impossible";
	else {
		char c = static_cast<char>(dVal);
		if (!std::isprint(c))
			std::cout << "Non displayable";
		else
			std::cout << "'" << c << "'";
	}
	std::cout << std::endl;

	std::cout << "int: ";
	if (conversionError || std::isnan(dVal)
		|| dVal < static_cast<double>(std::numeric_limits<int>::min())
		|| dVal > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "impossible";
	else {
		int i = static_cast<int>(dVal);
		std::cout << i;
	}
	std::cout << std::endl;

	std::cout << "float: ";
	float f = static_cast<float>(dVal);
	if (isPseudoLiteral(literal)) {

		if (literal.back() == 'f')
			std::cout << literal;
		else
			std::cout << literal << "f";
	} else if (conversionError) {
		std::cout << "impossible";
	} else {
		std::cout << std::fixed << std::setprecision(1) << f << "f";
	}
	std::cout << std::endl;

	std::cout << "double: ";
	if (isPseudoLiteral(literal)) {
		if (literal.back() == 'f')
			std::cout << literal.substr(0, literal.size() - 1);
		else
			std::cout << literal;
	} else if (conversionError) {
		std::cout << "impossible";
	} else {
		std::cout << std::fixed << std::setprecision(1) << dVal;
	}
	std::cout << std::endl;
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
