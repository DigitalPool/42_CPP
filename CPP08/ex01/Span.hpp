/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:33:13 by mac               #+#    #+#             */
/*   Updated: 2025/03/06 09:55:41 by mac              ###   ########.fr       */
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
	unsigned int _N;
	std::vector<int> _numbers;

public:
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int number);

	template <typename InputIterator>
	void addNumbers(InputIterator begin, InputIterator end) {
		for (InputIterator it = begin; it != end; ++it) {
			if (_numbers.size() >= _N)
				throw std::runtime_error("Span is full");
			_numbers.push_back(*it);
		}
	}

	int shortestSpan() const;
	int longestSpan() const;
};

#endif



