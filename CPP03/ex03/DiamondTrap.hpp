/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:10:14 by mac               #+#    #+#             */
/*   Updated: 2025/02/06 16:19:52 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap {
private:
	std::string _name;
public:
	DiamondTrap();
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap &operator=(const DiamondTrap &other);
	~DiamondTrap();

	void whoAmI();
	void attack(const std::string &name);
};

#endif
