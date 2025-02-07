/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:17:39 by mac               #+#    #+#             */
/*   Updated: 2025/02/06 21:21:40 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	*this = other;
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->type;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal makes sound wrongwrong..." << std::endl;
}
