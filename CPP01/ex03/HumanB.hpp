/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:38:04 by mac               #+#    #+#             */
/*   Updated: 2025/01/16 15:22:25 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB{
private:
	std::string _name;
	Weapon* _Weapon;


public:
	HumanB(const std::string& name);
	~HumanB();
	void setWeapon(Weapon& Weapon);
	void attack() const;
};

#endif
