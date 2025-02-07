/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:19:23 by mac               #+#    #+#             */
/*   Updated: 2025/01/15 20:25:13 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie{

	public:
		Zombie();
		Zombie(const std::string name);
		~Zombie();

		void announce(void);
		void setName(std::string name);

	private:
		std::string name;

};

Zombie* zombieHorde( int N, std::string name );

#endif
