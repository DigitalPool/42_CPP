/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:38:04 by mac               #+#    #+#             */
/*   Updated: 2025/01/16 15:17:56 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA{
	private:
	Weapon& _Weapon;
	std::string _name;

	public:
	HumanA(const std::string& name, Weapon& Weapon);
	~HumanA();
	void attack() const ;
};

#endif
