/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:54:35 by mac               #+#    #+#             */
/*   Updated: 2025/01/15 20:25:21 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie(){
	std::cout << this->name << ": is being destroyed..." << std::endl;
}

void Zombie::announce(void){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name){
	this->name = name;
}
