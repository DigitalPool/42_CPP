/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:20:15 by mac               #+#    #+#             */
/*   Updated: 2025/02/06 21:27:13 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	this->type = "WrongCat";
	std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	*this = other;
	std::cout << "WrongCat Copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat makes sound wrongmeowwwww" << std::endl;
}
