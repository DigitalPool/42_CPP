/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 00:36:30 by mac               #+#    #+#             */
/*   Updated: 2025/01/17 08:04:50 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){

}

void Harl::debug() {
    std::cout
        << MAGENTA << "[DEBUG] \"I'm not saying it's aliens, "
        << "but I'm definitely checking the logs...\""
        << RESET << std::endl;
}

void Harl::info() {
    std::cout
        << GREEN << "[INFO] \"Fun fact: 42 is the answer to life, "
        << "the universe, and everything. Also, everything is working fine.\""
        << RESET << std::endl;
}

void Harl::warning() {
    std::cout
        << YELLOW << "[WARNING] \"Things are getting spicy! "
        << "You might want to keep an extinguisher handy...\""
        << RESET << std::endl;
}

void Harl::error() {
    std::cout
        << RED << "[ERROR] \"It's all gone horribly wrong! "
        << "Grab some snacks and brace yourself—this may take a while.\""
        << RESET << std::endl;
}

void Harl::complain( std::string level){
	void (Harl::*ptr_memfuncts[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int level_num = 4;

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			while (i < level_num) {
				(this->*ptr_memfuncts[i])();
				i++;
			}
			return ;
		}
	}
}
