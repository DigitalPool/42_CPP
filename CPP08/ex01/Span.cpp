/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:13:29 by mac               #+#    #+#             */
/*   Updated: 2025/03/05 22:13:31 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <stdexcept>

// Constructor: initialize maximum capacity.
Span::Span(unsigned int n) : _N(n) {}

// Copy constructor.
Span::Span(const Span &other) : _N(other._N), _numbers(other._numbers) {}

// Assignment operator.
Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _N = other._N;
        _numbers = other._numbers;
    }
    return *this;
}

// Destructor.
Span::~Span() {}

// Adds a single number. Throws an exception if the Span is already full.
void Span::addNumber(int number) {
    if (_numbers.size() >= _N)
        throw std::runtime_error("Span is full");
    _numbers.push_back(number);
}

// Returns the shortest span (minimum difference between two consecutive numbers after sorting).
int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");

    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < tmp.size(); ++i) {
        int span = tmp[i] - tmp[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

// Returns the longest span (difference between the minimum and maximum elements).
int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");
    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());
    return maxVal - minVal;
}
