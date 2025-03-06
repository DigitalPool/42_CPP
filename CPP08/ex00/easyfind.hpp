/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:33:13 by mac               #+#    #+#             */
/*   Updated: 2025/03/05 22:09:07 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>  // for std::find
#include <iterator>   // for iterator traits
#include <exception>

// Define a custom exception to throw if the value is not found.
class NotFoundException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Value not found in container";
    }
};

// Function template easyfind:
// Takes a container (assumed to hold integers) by reference and an int value.
// Returns an iterator to the first occurrence of the value in the container.
// If the value is not found, throws NotFoundException.
template <typename T>
typename T::iterator easyfind(T &container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw NotFoundException();
    return it;
}

// Overload for constant containers.
template <typename T>
typename T::const_iterator easyfind(const T &container, int value) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw NotFoundException();
    return it;
}

#endif

