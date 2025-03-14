/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:01:51 by mac               #+#    #+#             */
/*   Updated: 2025/03/06 10:12:11 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include <vector>

int main() {
	try {
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		Span spLarge(10000);
		std::vector<int> numbers;
		for (int i = 0; i < 10000; i++) {
			numbers.push_back(i);
		}
		spLarge.addNumbers(numbers.begin(), numbers.end());
		std::cout << "Large span shortest span: " << spLarge.shortestSpan() << std::endl;
		std::cout << "Large span longest span: " << spLarge.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
