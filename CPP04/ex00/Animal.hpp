/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:17:14 by mac               #+#    #+#             */
/*   Updated: 2025/02/13 08:09:42 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
	protected:
		std::string type;

	public:
		Animal();
		// Animal(std::string type);
		Animal(const Animal &other);
		virtual ~Animal();
		Animal &operator=(const Animal &other);

		std::string getType() const;
		virtual void makeSound() const; // 'virtual' ensures dynamic dispatch
};

#endif

