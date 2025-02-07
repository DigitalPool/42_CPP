/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:38:09 by mac               #+#    #+#             */
/*   Updated: 2025/02/05 07:45:03 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap constructor for: "
			  << _name << " called " << std::endl;
}

/////////////////////////////////////////////////////////////////////////////

ScavTrap::ScavTrap(const ScavTrap &other) {
	*this = other;
	std::cout << "ScavTrap Copy constructor for: " << _name << " called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

/////////////////////////////////////////////////////////////////////////////

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor for " << _name << " called" << std::endl;
}

/////////////////////////////////////////////////////////////////////////////

void ScavTrap::attack(const std::string &target) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		std::cout << "ScavTrap " << _name << " attacks " << target << " causing "
					<< _attackDamage << " damage!!!" << std::endl;
		_energyPoints--;
	}
	else if (_energyPoints == 0) {
		std::cout << "ScavTrap " << _name
				  << " has no energy to attack!" << std::endl;
	}
	else {
		std::cout << "ScavTrap " << _name
				  << " has no hit points to attack!" << std::endl;
	}
}

/////////////////////////////////////////////////////////////////////////////

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " is now guarding the gate!" << std::endl;
}

