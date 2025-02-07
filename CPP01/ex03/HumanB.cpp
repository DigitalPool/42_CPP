/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:08:18 by mac               #+#    #+#             */
/*   Updated: 2025/01/16 15:23:37 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : _name(name), _Weapon(nullptr) {
	std::cout << this->_name << " is now on battle with no weapon "<< std::endl;
}

HumanB::~HumanB(){
	std::cout << this->_name << " has died." << std::endl;
}

void HumanB::setWeapon(Weapon& Weapon) {
	this->_Weapon = &Weapon;  // store address of the weapon
}

void HumanB::attack() const
{
	if (this->_Weapon) {
		std::cout << this->_name << " attacks with their "
				  << this->_Weapon->getType() << std::endl;
	} else {
		std::cout << this->_name << " has no weapon to attack with!" << std::endl;
	}
}

// HumanB::HumanB(std::string name) : _name(name) {
// 	std::cout << this->_name << " is now on battle with their but has not weapon" << std::endl;
// }
