/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:52:19 by mac               #+#    #+#             */
/*   Updated: 2025/02/05 07:31:21 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{

	// turn all these to protected
	protected:
		std::string _name;
		int	_hitPoints;
		int	_energyPoints;
		int	_attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string _name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();

		void attack (const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

# endif
