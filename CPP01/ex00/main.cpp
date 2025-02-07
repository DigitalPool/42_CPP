/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:36:08 by mac               #+#    #+#             */
/*   Updated: 2025/01/15 09:42:33 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void){
	Zombie* theNewZombie;

	theNewZombie = newZombie("Elemere");
	randomChump("Alvin");
	theNewZombie->announce();
	delete theNewZombie;
	return 0;
}
