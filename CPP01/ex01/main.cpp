/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:36:08 by mac               #+#    #+#             */
/*   Updated: 2025/01/15 20:19:25 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void){
	int N;
	N = 10;
	std::string name = "Zamba";

	Zombie* newZombieHorde;
	newZombieHorde = zombieHorde(N, name);

	for (int i = 0; i < N; i++)
	{
		newZombieHorde[i].announce();
	}

	delete[] newZombieHorde;

	return 0;
}
