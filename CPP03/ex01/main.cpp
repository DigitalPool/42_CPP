/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:14:37 by mac               #+#    #+#             */
/*   Updated: 2025/02/04 21:07:26 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	std::cout << "=== Creating a ClapTrap named Bob ===" << std::endl;
	ClapTrap bob("Bob");
	bob.attack("Enemy1");
	bob.takeDamage(5);
	bob.beRepaired(3);

	std::cout << "\n=== Creating a ScavTrap named Jim ===" << std::endl;
	ScavTrap jim("Jim");
	jim.attack("Enemy2");
	jim.takeDamage(20);
	jim.beRepaired(10);

	jim.guardGate();

	std::cout << "\n=== Now let's see destructors in action ===" << std::endl;

	return 0;
}
