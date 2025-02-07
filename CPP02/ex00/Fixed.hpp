/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:37:05 by mac               #+#    #+#             */
/*   Updated: 2025/01/19 19:57:57 by mac              ###   ########.fr       */
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
		Fixed( const Fixed &other );
		Fixed &operator = (const Fixed &other);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
