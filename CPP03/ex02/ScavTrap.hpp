/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:38:13 by mac               #+#    #+#             */
/*   Updated: 2025/02/06 10:01:25 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap();
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);
	~ScavTrap();

	void attack(const std::string &target);

	void guardGate();
};

#endif
