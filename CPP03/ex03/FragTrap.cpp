/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:44:36 by mac               #+#    #+#             */
/*   Updated: 2025/02/05 09:57:41 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << "FragTrap Default constructor called for "
			  << _name << std::endl;
}

FragTrap::FragTrap(const std::string &name) {
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << "FragTrap Named constructor called for "
			  << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) {
	*this = other;
	std::cout << "FragTrap Copy constructor called for "
			  << _name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called for "
			  << _name << std::endl;
}

/////////////////////////////////////////////////////////////////////////////

void FragTrap::attack(const std::string &target) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		std::cout << "FragTrap " << _name << " BLASTS " << target
				  << ", dealing " << _attackDamage << " points of damage!"
				  << std::endl;
		_energyPoints--;
	}
	else if (_energyPoints == 0) {
		std::cout << "FragTrap " << _name
				  << " has no energy to attack!" << std::endl;
	}
	else {
		std::cout << "FragTrap " << _name
				  << " has no HP to attack!" << std::endl;
	}
}

/////////////////////////////////////////////////////////////////////////////

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name
			  << " requests a positive high five from everyone!"
			  << std::endl;
}
