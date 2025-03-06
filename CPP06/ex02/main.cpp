/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:01:51 by mac               #+#    #+#             */
/*   Updated: 2025/03/06 08:30:40 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {
	std::srand(static_cast<unsigned int>(std::time(0)));

	Base* ptr = generate();

	std::cout << "Using pointer: ";
	identify(ptr);

	std::cout << "Using reference: ";
	identify(*ptr);

	delete ptr;
	return 0;
}
