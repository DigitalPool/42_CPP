/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:01:51 by mac               #+#    #+#             */
/*   Updated: 2025/03/05 22:05:01 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
}

// #include <iostream>
// #include "Array.hpp"

// int main() {
// 	// Test default constructor: empty array.
// 	Array<int> emptyArray;
// 	std::cout << "Empty array size: " << emptyArray.size() << std::endl;

// 	// Test constructor with a size parameter.
// 	Array<int> intArray(5);
// 	// Initialize the array.
// 	for (unsigned int i = 0; i < intArray.size(); i++) {
// 		intArray[i] = i * 10;
// 	}

// 	// Print the contents of intArray.
// 	std::cout << "Int array contents:" << std::endl;
// 	for (unsigned int i = 0; i < intArray.size(); i++) {
// 		std::cout << intArray[i] << " ";
// 	}
// 	std::cout << std::endl;

// 	// Test the copy constructor.
// 	Array<int> copyArray = intArray;
// 	// Modify the original array to check that the copy is deep.
// 	intArray[0] = 999;
// 	std::cout << "After modifying intArray[0] to 999:" << std::endl;
// 	std::cout << "Original intArray: ";
// 	for (unsigned int i = 0; i < intArray.size(); i++) {
// 		std::cout << intArray[i] << " ";
// 	}
// 	std::cout << std::endl;
// 	std::cout << "Copy array: ";
// 	for (unsigned int i = 0; i < copyArray.size(); i++) {
// 		std::cout << copyArray[i] << " ";
// 	}
// 	std::cout << std::endl;

// 	// Test out-of-bounds access: this should throw an exception.
// 	try {
// 		std::cout << "Attempting to access element at index 5:" << std::endl;
// 		std::cout << intArray[5] << std::endl;
// 	} catch (const std::exception& e) {
// 		std::cout << "Exception caught: Index out of bounds" << std::endl;
// 	}

// 	return 0;
// }
