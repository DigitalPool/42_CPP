/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:17:14 by mac               #+#    #+#             */
/*   Updated: 2025/02/06 19:43:49 by mac              ###   ########.fr       */
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
		Animal &operator=(const Animal &other);

		virtual ~Animal();

		std::string getType() const;
		virtual void makeSound() const; // 'virtual' ensures dynamic dispatch
};

#endif

