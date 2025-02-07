/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:09:04 by mac               #+#    #+#             */
/*   Updated: 2025/02/04 14:48:13 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::frac_bit = 8;

Fixed::Fixed() : fp_nbr(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	this->fp_nbr = other.fp_nbr;
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator = ( const Fixed &input ) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &input)
		this->fp_nbr = input.fp_nbr;
	return *this;
}

Fixed::~Fixed(){
	// std::cout << "Destructor called" << std::endl;
}

///////////////////////////////////////////////////////////////

Fixed::Fixed( const int constInt ){
	// std::cout << "Int constructor called" << std::endl;
	this->fp_nbr = constInt << frac_bit;
}

Fixed::Fixed( const float constFlt ){
	// std::cout << "Float constructor called" << std::endl;
	this->fp_nbr = static_cast<int>(roundf(constFlt * (1 << frac_bit)));
}

///////////////////////////////////////////////////////////////

int Fixed::getRawBits( void ) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->fp_nbr);
}

void Fixed::setRawBits( int const raw ) {
	this->fp_nbr = raw;
}

///////////////////////////////////////////////////////////////

float Fixed::toFloat( void ) const{
	return ((float)this->fp_nbr / (float)(1 << this->frac_bit));
}

int Fixed::toInt(void) const
{
	return (this->fp_nbr >> this->frac_bit);
}

///////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return os;
 }

////////////////////////////////////////////////////////

bool Fixed::operator>(const Fixed &rhs) const {
	return (this->fp_nbr > rhs.fp_nbr);
}

bool Fixed::operator<(const Fixed &rhs) const {
	return (this->fp_nbr < rhs.fp_nbr);
}

bool Fixed::operator>=(const Fixed &rhs) const {
	return (this->fp_nbr >= rhs.fp_nbr);
}

bool Fixed::operator<=(const Fixed &rhs) const {
	return (this->fp_nbr <= rhs.fp_nbr);
}

bool Fixed::operator==(const Fixed &rhs) const {
	return (this->fp_nbr == rhs.fp_nbr);
}

bool Fixed::operator!=(const Fixed &rhs) const {
	return (this->fp_nbr != rhs.fp_nbr);
}

////////////////////////////////////////////////////////


Fixed Fixed::operator+(const Fixed &rhs) const {
	Fixed temp;
	temp.fp_nbr = this->fp_nbr + rhs.fp_nbr;
	return temp;
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	Fixed temp;
	temp.fp_nbr = this->fp_nbr - rhs.fp_nbr;
	return temp;
}

////////////////////////////////////////////////////////


Fixed Fixed::operator*(const Fixed &rhs) const {
	return (Fixed(toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs) const {
	return (Fixed(toFloat() / rhs.toFloat()));
}

////////////////////////////////////////////////////////

Fixed &Fixed::operator++() {
	this->fp_nbr++;
	return *this;
}

// Post-increment: a++
Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed &Fixed::operator--() {
	this->fp_nbr--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	--(*this);
	return temp;
}

////////////////////////////////////////////////////////

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return (a);
	return (b);
}

