/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:09:04 by mac               #+#    #+#             */
/*   Updated: 2025/01/19 22:19:25 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::frac_bit = 8;

Fixed::Fixed() : fp_nbr(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	this->fp_nbr = other.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
	getRawBits();
}

Fixed &Fixed::operator = ( const Fixed &other ) {
	std::cout << "Copy assignment operator called" << std::endl;
	getRawBits();
	if (this != &other)
		this->fp_nbr = other.getRawBits();
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
