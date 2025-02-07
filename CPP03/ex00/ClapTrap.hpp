/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:52:19 by mac               #+#    #+#             */
/*   Updated: 2025/02/04 20:35:13 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{

	private:
		std::string _name;
		int	_hitPoint;
		int	_energyPoint;
		int	_attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string _name);
		~ClapTrap();

		void attack (const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

# endif
