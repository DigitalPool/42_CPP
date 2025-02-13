/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:17:14 by mac               #+#    #+#             */
/*   Updated: 2025/02/13 09:35:54 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

class Animal {
	protected:
		std::string type;
		Animal();

	public:
		// Animal(std::string type);
		Animal(const Animal &other);
		virtual ~Animal();

		Animal &operator=(const Animal &other);

		std::string getType() const;
		virtual void makeSound() const = 0; // adding '= 0' makes it uninstantiatable
};

#endif

