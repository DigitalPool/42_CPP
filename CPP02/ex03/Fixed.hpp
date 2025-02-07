/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:37:05 by mac               #+#    #+#             */
/*   Updated: 2025/02/04 15:48:21 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int _raw;
	static const int _fracBits = 8;

public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	Fixed(const int val);
	Fixed(const float val);

	float toFloat(void) const;
	int toInt(void) const;

	int getRawBits(void) const;
	void setRawBits(int const raw);

	bool  operator==(const Fixed &rhs) const;
	bool  operator!=(const Fixed &rhs) const;
	bool  operator<(const Fixed &rhs)  const;
	bool  operator>(const Fixed &rhs)  const;
	Fixed operator-(const Fixed &rhs)  const;
	Fixed operator*(const Fixed &rhs)  const;
	Fixed operator+(Fixed const &rhs) const;
	Fixed operator/(Fixed const &rhs) const;

};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
