/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:00:17 by mac               #+#    #+#             */
/*   Updated: 2025/02/05 07:33:15 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// When ClapTrap attacks, it causes its target to lose <attack damage> hit points.
// When ClapTrap repairs itself, it gets <amount> hit points back. Attacking and
// repairing cost 1 energy point each. Of course, ClapTrap can’t do anything if it
// has no hit points or energy points left. However, since these exercises serve as
// an introduction, the ClapTrap instances should not interact directly with one
// another, and the parameters will not refer to another instance of ClapTrap.

ClapTrap::ClapTrap() : _name("DefaultClap"), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "Default Claptrap Contructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "Claptrap Contructor named " << name << " called" << std::endl;
}

ClapTrap::~ClapTrap(){
		std::cout << "Claptrap Destructor called for " << this->_name << std::endl;
}

void ClapTrap::attack (const std::string& target) {

	if (this->_energyPoints > 0 && this->_hitPoints > 0){
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage " << std::endl;
		this->_energyPoints--;
	}
	else if (this->_energyPoints == 0){
		std::cout << "ClapTrap " << this->_name << " cannot attack " << target << " because there is no more energy left " << std::endl;
	}
	else{
		std::cout << "ClapTrap " << this->_name << " cannot attack " << target << " because there is no hit points left " << std::endl;
	}
}

/////////////////////////////////////////////////////////////////////////////

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other) {
	*this = other;
	std::cout << "ClapTrap Copy constructor called for ["
			  << _name << "]" << std::endl;
}

// Copy assignment operator
ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_name         = other._name;
		this->_hitPoints    = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}


/////////////////////////////////////////////////////////////////////////////

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints > (int)amount){
		std::cout << "ClapTrap " << this->_name << " has lost " << amount << " hit points " << std::endl;
		this->_hitPoints-= amount;
	}
	else if (this->_hitPoints < (int)amount){
		std::cout << "ClapTrap " << this->_name << " has died, let it rest in peace " << std::endl;
		this->_hitPoints = 0;
	}
	else
		std::cout << "ClapTrap " << this->_name << " has " << this->_hitPoints << " hit points left " << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_hitPoints == 0){
		std::cout << "ClapTrap " << this->_name << " cannot repair itself because it has no hit points left "<< std::endl;
	}
	else if (this->_energyPoints == 0){
		std::cout << "ClapTrap " << this->_name << " cannot repair itself because it has no energy left "<< std::endl;
	}
	else if (this->_hitPoints > 0 && this->_energyPoints > 0){
		std::cout << "ClapTrap " << this->_name << " has repaired it self with " << amount << " hit points " << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
}
