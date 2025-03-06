/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:01:51 by mac               #+#    #+#             */
/*   Updated: 2025/03/05 22:11:05 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    // Test with a std::vector<int>
    std::vector<int> vec;
    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "Found value 5 in vector at position: "
                  << std::distance(vec.begin(), it) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        // Try to find a value not in the vector.
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "Found value 42 in vector at position: "
                  << std::distance(vec.begin(), it) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test with a std::list<int>
    std::list<int> lst;
    for (int i = 10; i < 20; i++) {
        lst.push_back(i);
    }

    try {
        // We don't need the iterator if we are only confirming that the element exists.
        easyfind(lst, 15);
        std::cout << "Found value 15 in list." << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        easyfind(lst, 100);
        std::cout << "Found value 100 in list." << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
