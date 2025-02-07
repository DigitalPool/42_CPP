/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:20:26 by mac               #+#    #+#             */
/*   Updated: 2025/01/15 19:57:40 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N < 1){
		std::cout << "Horde number cannot be less than 1" << std::endl;
		return (NULL);
	}

	Zombie* zombieHorde;

	zombieHorde = new Zombie[N];

	if (zombieHorde == NULL) {
		std::cout << "Horde allocation failed" << std::endl;
		return (NULL);
	}

	for (int i = 0; i < N; i++)
	{
		zombieHorde[i].setName(name);
	}

	return zombieHorde;
}
