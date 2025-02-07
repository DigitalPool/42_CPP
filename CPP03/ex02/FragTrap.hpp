/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:44:41 by mac               #+#    #+#             */
/*   Updated: 2025/02/05 09:47:01 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &other);
	~FragTrap();

	void attack(const std::string &target);

	void highFivesGuys(void);
};

#endif
