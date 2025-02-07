/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:25:24 by mac               #+#    #+#             */
/*   Updated: 2025/01/16 14:18:34 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(const std::string type) : _type(type){

};

Weapon::~Weapon(void)
{
}

const std::string& Weapon::getType() const{
	return this->_type;
}

void Weapon::setType(const std::string newType)
{
	this->_type = newType;
};
