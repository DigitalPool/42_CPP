/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:37:05 by mac               #+#    #+#             */
/*   Updated: 2025/02/04 13:46:56 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
	private:
		int fp_nbr;
		static const int frac_bit;

	public:
		Fixed();
		Fixed( const Fixed &other);

		Fixed( const int constInt );
		Fixed( const float constFlt );

		Fixed &operator = (const Fixed &input);

		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;

		bool operator>(const Fixed &input) const;
		bool operator<(const Fixed &input) const;
		bool operator>=(const Fixed &input) const;
		bool operator<=(const Fixed &input) const;
		bool operator==(const Fixed &input) const;
		bool operator!=(const Fixed &input) const;

		Fixed operator+(const Fixed &input) const;
		Fixed operator-(const Fixed &input) const;
		Fixed operator*(const Fixed &input) const;
		Fixed operator/(const Fixed &input) const;

		Fixed &operator++();
		Fixed &operator--();

		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);

		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

#endif
