/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:01:51 by mac               #+#    #+#             */
/*   Updated: 2025/03/17 16:26:02 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <vector>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: no numbers provided." << std::endl;
        return 1;
    }

    // Parse the arguments and check that each is a positive integer.
    std::vector<int> numbers;
    for (int i = 1; i < argc; i++) {
        std::istringstream iss(argv[i]);
        int num;
        if (!(iss >> num) || num < 0) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        numbers.push_back(num);
    }

    // Display the unsorted sequence.
    std::cout << "Before: ";
    for (size_t i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    // Create a PmergeMe instance from the vector of numbers.
    PmergeMe sorter(numbers);
    sorter.sort();

    return 0;
}
