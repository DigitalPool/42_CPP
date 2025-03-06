/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:57:54 by mac               #+#    #+#             */
/*   Updated: 2025/03/06 10:21:25 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(nullptr), _size(0) {}


template <typename T>
Array<T>::Array(unsigned int n) : _array(nullptr), _size(n) {
	if (n > 0)
		_array = new T[n]();
}

template <typename T>
Array<T>::Array(const Array<T>& other) : _array(nullptr), _size(other._size) {
	if (_size > 0) {
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++) {
			_array[i] = other._array[i];
		}
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this != &other) {
		// Free current memory.
		if (_array)
			delete[] _array;
		_size = other._size;
		_array = ( _size > 0 ? new T[_size] : nullptr );
		for (unsigned int i = 0; i < _size; i++) {
			_array[i] = other._array[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] _array;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw std::exception();
	return _array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= _size)
		throw std::exception();
	return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}

#endif
