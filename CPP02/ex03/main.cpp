/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 08:52:01 by mac               #+#    #+#             */
/*   Updated: 2025/02/04 17:16:53 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(0.0f, 10.0f);

	Point inside(3.0f, 2.0f);
	Point outside(11.0f, 5.0f);
	Point edge(5.0f, 5.0f);   // actually on the line of a right triangle?

	std::cout << "Inside?		" << (bsp(a,b,c, inside) ? "Yes" : "No") << std::endl;
	std::cout << "Outside?	" << (bsp(a,b,c, outside)? "Yes" : "No") << std::endl;
	std::cout << "Edge?		" << (bsp(a,b,c, edge)   ? "Yes" : "No") << std::endl;

	return 0;
}
