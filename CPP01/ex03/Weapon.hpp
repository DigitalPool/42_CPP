/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:25:24 by mac               #+#    #+#             */
/*   Updated: 2025/01/16 15:19:35 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon{

	private:
		std::string _type;

	public:
		Weapon(std::string type);
		~Weapon();

		const std::string& getType() const;
		void setType(const std::string newType);
};

#endif
