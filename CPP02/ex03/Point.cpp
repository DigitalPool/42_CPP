/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:20:06 by mac               #+#    #+#             */
/*   Updated: 2025/02/04 15:57:23 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {

}

Point::Point(const float px, const float py) : x(px), y(py) {

}

Point::Point(const Point &other) : x(other.x), y(other.y) {

}

Point &Point::operator=(const Point &other) {
	(void)other;
	return *this;
}

Point::~Point() {

}

Fixed Point::getX() const {
	return this->x;
}

Fixed Point::getY() const {
	return this->y;
}
