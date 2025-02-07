/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:50:43 by mac               #+#    #+#             */
/*   Updated: 2025/02/06 22:27:48 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal{
	private:
		Brain* _brain;

	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);

		virtual ~Dog();

		std::string getType() const;
		virtual void makeSound() const;
};

#endif
