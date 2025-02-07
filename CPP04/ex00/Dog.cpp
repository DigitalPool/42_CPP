/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:53:33 by mac               #+#    #+#             */
/*   Updated: 2025/02/06 22:25:27 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	std::cout << "Default constructor for Dog called" << std::endl;
}

Dog::~Dog(){
	std::cout << "Default destructor for Dog called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	*this = other;
	std::cout << "Dog Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other){
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

std::string Dog::getType() const{
	return (this->type);
}

void Dog::makeSound() const{
	std::cout <<  this->type << " makes sound baaaaaaaark" <<std::endl;
}
