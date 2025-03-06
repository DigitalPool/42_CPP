/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:01:51 by mac               #+#    #+#             */
/*   Updated: 2025/03/06 09:06:41 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printValue(const T &x) {
	std::cout << x << std::endl;
}


void printInt(const int &x) {
	std::cout << x << " ";
}

int main() {
	int arrInt[] = {1, 2, 3, 4, 5};
	size_t lenInt = sizeof(arrInt) / sizeof(arrInt[0]);
	std::cout << "Int array: ";
	iter(arrInt, lenInt, printInt);
	std::cout << std::endl;

	std::string arrStr[] = {"Hello", "World", "C++", "Templates"};
	size_t lenStr = sizeof(arrStr) / sizeof(arrStr[0]);
	std::cout << "String array:" << std::endl;
	iter(arrStr, lenStr, printValue<std::string>);

	double arrDouble[] = {3.14, 2.71, 1.41};
	size_t lenDouble = sizeof(arrDouble) / sizeof(arrDouble[0]);
	std::cout << "Double array:" << std::endl;
	iter(arrDouble, lenDouble, printValue<double>);

	return 0;
}
