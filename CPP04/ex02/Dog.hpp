/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:50:43 by mac               #+#    #+#             */
/*   Updated: 2025/02/13 08:51:09 by mac              ###   ########.fr       */
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
		virtual ~Dog();

		Dog &operator=(const Dog &other);

		std::string getType() const;
		virtual void makeSound() const;
		void getIdeas() const;
		void setIdeas(size_t idea_idx, std::string idea);
};

#endif
