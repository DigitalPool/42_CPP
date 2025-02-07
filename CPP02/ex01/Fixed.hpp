/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:37:05 by mac               #+#    #+#             */
/*   Updated: 2025/02/04 09:13:25 by mac              ###   ########.fr       */
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
		Fixed &operator = (const Fixed &other);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &os, Fixed const &fixed);

#endif
