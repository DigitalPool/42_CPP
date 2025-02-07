/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:10:08 by mac               #+#    #+#             */
/*   Updated: 2025/02/06 16:31:26 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// redefine functions are bound at compile time
// overriding function are bound at run time
// Polymorphism requires references as pointers
// if a class inherits a virtual function it must override it

#include "DiamondTrap.hpp"

// class DiamondTrap : public ScavTrap, public FragTrap {
// private:
// 	std::string _name;
// public:
// 	DiamondTrap();
// 	DiamondTrap(const std::string &name);
// 	DiamondTrap(const DiamondTrap &other);
// 	DiamondTrap &operator=(const DiamondTrap &other);
// 	~DiamondTrap();

// 	void whoAmI();
// };

DiamondTrap::DiamondTrap() {
	std::cout << "DiamondTrap default constructor called for " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(){
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;

	std::cout << "DiamondTrap named constructor called for " << this->_name << std::endl;

}

DiamondTrap::~DiamondTrap(){

	std::cout << "DiamondTrap destructor called for " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	*this = other;
	std::cout << "DiamondTrap copy constructor called for " << _name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other){
	std::cout << "DiamondTrap copy assignment operator called.\n";
	if (this != &other){
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
		ClapTrap::_name = other.ClapTrap::_name;
	}
	return (*this);
};

void DiamondTrap::whoAmI(){
	std::cout << "[DiamondTrap] My name is " << _name << ", and my ClapTrap name is " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string &name){
	ScavTrap::attack(name);
}
