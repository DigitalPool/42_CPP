/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:14:37 by mac               #+#    #+#             */
/*   Updated: 2025/02/06 16:28:38 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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

	std::cout << "\n=== Creating a FragTrap named Sally ===" << std::endl;
	FragTrap sally("Sally");
	sally.attack("BadGuy");
	sally.takeDamage(15);
	sally.beRepaired(5);
	sally.highFivesGuys();

	std::cout << "\n=== Creating a default FragTrap (no name) ===" << std::endl;
	FragTrap unnamedFrag;
	unnamedFrag.attack("RandomTarget");
	unnamedFrag.highFivesGuys();

	// --------------------------- DiamondTrap Tests --------------------------- //
	std::cout << "\n=== Creating a DiamondTrap named Gem ===" << std::endl;
	DiamondTrap gem("Gem");
	gem.attack("TreasureMonster");   // Inherited from ScavTrap or FragTrap, as per your design
	gem.takeDamage(30);
	gem.beRepaired(15);
	gem.whoAmI();  // DiamondTrap unique method to show its name + ClapTrap name

	// Drain energy from gem
	std::cout << "\n--- Draining Gem's energy ---" << std::endl;
	for (int i = 0; i < 5; i++) {
		gem.attack("EnergyDummy");
	}
	gem.attack("NoEnergyLeft"); // should fail if no energy

	std::cout << "\n=== Creating a default DiamondTrap (no name) ===" << std::endl;
	DiamondTrap unnamedDiamond;
	unnamedDiamond.whoAmI(); // see the default naming scheme
	unnamedDiamond.attack("RandomFoe");

	// Test copy constructor
	std::cout << "\n=== Creating a copy of Gem using the DiamondTrap copy constructor ===" << std::endl;
	DiamondTrap gemCopy(gem);
	gemCopy.whoAmI();
	gemCopy.attack("CopyTarget");

	// Test assignment operator
	std::cout << "\n=== Assigning unnamedDiamond = gemCopy ===" << std::endl;
	unnamedDiamond = gemCopy;
	unnamedDiamond.whoAmI();
	unnamedDiamond.attack("AssignedEnemy");

	// ------------------------------------------------------------------------ //

	std::cout << "\n=== Now let's see destructors in action ===" << std::endl;
	return 0;
}
