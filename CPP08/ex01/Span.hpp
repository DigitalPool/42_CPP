/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:33:13 by mac               #+#    #+#             */
/*   Updated: 2025/03/05 22:13:07 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <stdexcept>
#include <iterator>
#include <algorithm>

class Span {
private:
    unsigned int _N;              // Maximum number of elements
    std::vector<int> _numbers;    // Storage for numbers

public:
    // Constructor: takes the maximum capacity.
    Span(unsigned int n);

    // Copy constructor and assignment operator.
    Span(const Span &other);
    Span &operator=(const Span &other);

    // Destructor.
    ~Span();

    // Adds a single number to the Span. Throws an exception if the Span is full.
    void addNumber(int number);

    // Templated function: adds numbers from a range of iterators.
    template <typename InputIterator>
    void addNumbers(InputIterator begin, InputIterator end) {
        for (InputIterator it = begin; it != end; ++it) {
            if (_numbers.size() >= _N)
                throw std::runtime_error("Span is full");
            _numbers.push_back(*it);
        }
    }

    // Returns the shortest span between any two numbers.
    // Throws an exception if there are fewer than 2 numbers.
    int shortestSpan() const;

    // Returns the longest span between any two numbers.
    // Throws an exception if there are fewer than 2 numbers.
    int longestSpan() const;
};

#endif



