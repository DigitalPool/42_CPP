/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:19:50 by mac               #+#    #+#             */
/*   Updated: 2025/02/04 15:55:46 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
	Fixed const x;
	Fixed const y;

public:
	Point();
	Point(const Point &other);
	Point &operator=(const Point &other);
	~Point();
	Point(const float px, const float py);
	Fixed getX() const;
	Fixed getY() const;
};

#endif
