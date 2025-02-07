/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:09:04 by mac               #+#    #+#             */
/*   Updated: 2025/02/04 15:54:30 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>   // for roundf

Fixed::Fixed() : _raw(0) {

}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		this->_raw = other._raw;
	}
	return *this;
}

Fixed::~Fixed(){

}
////////////////////////////////////////////////////////////////////

Fixed::Fixed(const int val) {
	this->_raw = val << _fracBits;
}

Fixed::Fixed(const float val) {
	this->_raw = static_cast<int>(std::roundf(val * (1 << _fracBits)));
}

////////////////////////////////////////////////////////////////////
float Fixed::toFloat(void) const {
	return static_cast<float>(this->_raw) / (1 << _fracBits);
}

int Fixed::toInt(void) const {
	return this->_raw >> _fracBits;
}

////////////////////////////////////////////////////////////////////
int Fixed::getRawBits(void) const {
	return this->_raw;
}

void Fixed::setRawBits(int const raw) {
	this->_raw = raw;
}

////////////////////////////////////////////////////////////////////
bool Fixed::operator==(const Fixed &rhs) const {
	return (this->_raw == rhs._raw);
}
bool Fixed::operator!=(const Fixed &rhs) const {
	return (this->_raw != rhs._raw);
}
bool Fixed::operator<(const Fixed &rhs) const {
	return (this->_raw < rhs._raw);
}
bool Fixed::operator>(const Fixed &rhs) const {
	return (this->_raw > rhs._raw);
}

////////////////////////////////////////////////////////////////////
Fixed Fixed::operator-(const Fixed &rhs) const {
	Fixed temp;
	temp._raw = this->_raw - rhs._raw;
	return temp;
}

Fixed Fixed::operator+(Fixed const &rhs) const {
	Fixed temp;
	temp._raw = this->_raw + rhs._raw;
	return temp;
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	return (Fixed(toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs) const {
	return (Fixed(toFloat() / rhs.toFloat()));
}

////////////////////////////////////////////////////////////////////
std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}

