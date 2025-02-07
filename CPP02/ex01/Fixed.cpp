/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:09:04 by mac               #+#    #+#             */
/*   Updated: 2025/02/04 08:57:53 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::frac_bit = 8;

Fixed::Fixed() : fp_nbr(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	this->fp_nbr = other.fp_nbr;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed( const int constInt ){
	std::cout << "Int constructor called" << std::endl;
	this->fp_nbr = constInt << frac_bit;
}

Fixed::Fixed( const float constFlt ){
	std::cout << "Float constructor called" << std::endl;
	this->fp_nbr = static_cast<int>(roundf(constFlt * (1 << frac_bit)));
}

Fixed &Fixed::operator = ( const Fixed &other ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fp_nbr = other.fp_nbr;
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fp_nbr);
}

void Fixed::setRawBits( int const raw ) {
	this->fp_nbr = raw;
}

float Fixed::toFloat( void ) const{
	return ((float)this->fp_nbr / (float)(1 << this->frac_bit));
}

int Fixed::toInt(void) const
{
	return (this->fp_nbr >> this->frac_bit);
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return os;
 }
