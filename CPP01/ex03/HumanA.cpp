/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:08:18 by mac               #+#    #+#             */
/*   Updated: 2025/01/16 15:13:00 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& Weapon) : _Weapon(Weapon), _name(name) {

	std::cout << this->_name << " is now on battle with their " << this->_Weapon.getType() << std::endl;
}

HumanA::~HumanA(){
	std::cout << this->_name << " has died." << std::endl;
}

void HumanA::attack(void)const
{
	std::cout << this->_name << " attacks with their " << this->_Weapon.getType() << "." << std::endl;
}
