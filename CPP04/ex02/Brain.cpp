/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:31:44 by mac               #+#    #+#             */
/*   Updated: 2025/02/06 23:06:37 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain Default constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = "Random idea #" + std::to_string(i);
	}
}

Brain::Brain(const Brain &other) {
	*this = other;
	std::cout << "Brain Copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain Destructor called" << std::endl;
}
