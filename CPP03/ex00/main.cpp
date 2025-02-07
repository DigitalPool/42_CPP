/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:14:37 by mac               #+#    #+#             */
/*   Updated: 2025/02/04 20:36:47 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main() {
	// Create a ClapTrap named "Bob" (constructor should print a message)
	ClapTrap bob("Bob");

	// Bob attacks a target (costs 1 energy, prints an attack message)
	bob.attack("TargetDummy");

	// Bob takes some damage
	bob.takeDamage(4);

	// Bob repairs himself
	bob.beRepaired(2);

	// Show what happens when Bob runs out of hit points or energy
	// Let's artificially deplete Bob's energy
	for (int i = 0; i < 10; i++) {
		bob.attack("ExpendableDummy");
	}

	// Now Bob has no more energy; additional actions should fail
	bob.attack("AnotherDummy");
	bob.beRepaired(5);

	// Create another ClapTrap named "Alice"
	ClapTrap alice("Alice");

	// Alice takes damage bigger than her current HP
	alice.takeDamage(12);

	// Try to repair Alice after HP goes to 0 (should not work)
	alice.beRepaired(2);

	// Program ends, destructors should be called automatically
	return 0;
}
