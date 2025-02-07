/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:20:21 by mac               #+#    #+#             */
/*   Updated: 2025/02/04 18:28:28 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed absF(const Fixed &val) {
	if (val > Fixed(0)) {
		return val;
	} else {
		return val * Fixed(-1);
	}
}

static Fixed area(Point const &p1, Point const &p2, Point const &p3) {
	Fixed x1 = p2.getX() - p1.getX();
	Fixed y1 = p2.getY() - p1.getY();

	Fixed x2 = p3.getX() - p1.getX();
	Fixed y2 = p3.getY() - p1.getY();

	// Cross product magnitude = |x1*y2 - y1*x2|
	Fixed cross = (x1 * y2) - (y1 * x2);
	cross = absF(cross);

	// area = half cross magnitude of a parallelogram
	return cross / Fixed(2);
}

// The bsp function
bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed areaABC = area(a, b, c);

	Fixed areaPAB = area(point, a, b);
	Fixed areaPBC = area(point, b, c);
	Fixed areaPCA = area(point, c, a);

	// if any of the distances is equal to 0, the triangle is faulty
	if (areaPAB == Fixed(0) || areaPBC == Fixed(0) || areaPCA == Fixed(0))
		return false;

	// Compare sum of sub-areas with main area
	Fixed sumSub = areaPAB + areaPBC + areaPCA;

	// If they match exactly => inside
	return (sumSub == areaABC);
}
