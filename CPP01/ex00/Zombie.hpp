/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:56:56 by mac               #+#    #+#             */
/*   Updated: 2025/01/15 07:47:38 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie{

	public:
		Zombie(const std::string name);
		~Zombie();

		void announce(void);

	private:
		std::string name;

};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
