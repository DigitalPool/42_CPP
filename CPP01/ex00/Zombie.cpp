/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:54:35 by mac               #+#    #+#             */
/*   Updated: 2025/01/15 09:36:27 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name){
	std::cout << this->name << ": is being created..." << std::endl;
}

Zombie::~Zombie(){
	std::cout << this->name << ": is being destroyed..." << std::endl;
}

void Zombie::announce(void){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
