/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:33:13 by mac               #+#    #+#             */
/*   Updated: 2025/03/06 10:21:47 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>
#include "Array.tpp"

template <typename T>
class Array {
	private:
		T*			_array;
		unsigned int _size;

	public:
		Array();
		Array(unsigned int n);

		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		unsigned int size() const;
};

#endif
