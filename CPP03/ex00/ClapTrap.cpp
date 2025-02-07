/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:00:17 by mac               #+#    #+#             */
/*   Updated: 2025/02/04 20:37:09 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// When ClapTrap attacks, it causes its target to lose <attack damage> hit points.
// When ClapTrap repairs itself, it gets <amount> hit points back. Attacking and
// repairing cost 1 energy point each. Of course, ClapTrap can’t do anything if it
// has no hit points or energy points left. However, since these exercises serve as
// an introduction, the ClapTrap instances should not interact directly with one
// another, and the parameters will not refer to another instance of ClapTrap.

ClapTrap::ClapTrap() : _name("DefaultClap"), _hitPoint(10), _energyPoint(10), _attackDamage(0){
	std::cout << "Default Claptrap Contructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0){
	std::cout << "Claptrap Contructor named " << name << " called" << std::endl;
}

ClapTrap::~ClapTrap(){
		std::cout << "Claptrap Destructor called for " << this->_name << std::endl;
}

void ClapTrap::attack (const std::string& target) {

	if (this->_energyPoint > 0 && this->_hitPoint > 0){
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage " << std::endl;
		this->_energyPoint--;
	}
	else if (this->_energyPoint == 0){
		std::cout << "ClapTrap " << this->_name << " cannot attack " << target << " because there is no more energy left " << std::endl;
	}
	else{
		std::cout << "ClapTrap " << this->_name << " cannot attack " << target << " because there is no hit points left " << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoint > (int)amount){
		std::cout << "ClapTrap " << this->_name << " has lost " << amount << " hit points " << std::endl;
		this->_hitPoint-= amount;
	}
	else if (this->_hitPoint < (int)amount){
		std::cout << "ClapTrap " << this->_name << " has died, let it rest in peace " << std::endl;
		this->_hitPoint = 0;
	}
	else
		std::cout << "ClapTrap " << this->_name << " has " << this->_hitPoint << " hit points left " << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_hitPoint == 0){
		std::cout << "ClapTrap " << this->_name << " cannot repair itself because it has no hit points left "<< std::endl;
	}
	else if (this->_energyPoint == 0){
		std::cout << "ClapTrap " << this->_name << " cannot repair itself because it has no energy left "<< std::endl;
	}
	else if (this->_hitPoint > 0 && this->_energyPoint > 0){
		std::cout << "ClapTrap " << this->_name << " has repaired it self with " << amount << " hit points " << std::endl;
		this->_hitPoint += amount;
		this->_energyPoint--;
	}
}
