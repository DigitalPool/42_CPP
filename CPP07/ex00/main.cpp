/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:01:51 by mac               #+#    #+#             */
/*   Updated: 2025/03/05 21:36:06 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "whatever.hpp"

int main() {
	int y = 2;
	int z = 3;
	std::cout << "Integers:" << std::endl;
	std::cout << "Initial values: y = " << y << ", z = " << z << std::endl;
	::swap(y, z);
	std::cout << "After swap: y = " << y << ", z = " << z << std::endl;
	std::cout << "min(y, z) = " << ::min(y, z) << std::endl;
	std::cout << "max(y, z) = " << ::max(y, z) << std::endl;

	std::string s1 = "apple";
	std::string s2 = "banana";
	std::cout << "\nStrings:" << std::endl;
	std::cout << "Initial values: s1 = " << s1 << ", s2 = " << s2 << std::endl;
	::swap(s1, s2);
	std::cout << "After swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;
	std::cout << "min(s1, s2) = " << ::min(s1, s2) << std::endl;
	std::cout << "max(s1, s2) = " << ::max(s1, s2) << std::endl;

	std::cout << std::endl;
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "subject Test" << std::endl;
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << std::endl;

	int a = 2; int b = 3; ::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1"; std::string d = "chaine2";

	::swap(c, d); std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}
