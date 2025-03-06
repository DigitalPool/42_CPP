/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:48:45 by mac               #+#    #+#             */
/*   Updated: 2025/03/05 17:02:21 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cctype>
#include <cerrno>
#include <cmath>

// Write a class ScalarConverter that will contain only one static method "convert"
// that will takes as parameter a string representation of a C++ literal in its most
// common form and output its value in the following serie of scalar types : • char •
// int • float • double As this class doesn’t need to store anything at all, this class
// must not be instanciable by users. Except for char parameters, only the decimal
// notation will be used. Examples of char literals: ’c’, ’a’, ... To make things simple,
// please note that non displayable characters shouldn’t be used as inputs. If a conversion
// to char is not displayable, prints an informative message. Examples of int literals:
// 0,-42, 42... Examples of float literals: 0.0f,-4.2f, 4.2f... You have to handle these
// pseudo literals as well (you know, for science):-inff, +inff 7C++- Module 06 and nanf.
// C++ casts Examples of double literals: 0.0,-4.2, 4.2... You have to handle these pseudo
// literals as well (you know, for fun):-inf, +inf and nan.

class ScalarConverter{
	public:
		static void convert(const std::string& literal);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		~ScalarConverter();

		ScalarConverter &operator=(const ScalarConverter &src);
};



