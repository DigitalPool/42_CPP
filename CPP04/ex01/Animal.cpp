/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:14:12 by mac               #+#    #+#             */
/*   Updated: 2025/02/13 08:11:11 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Default"){
	std::cout <<  "Default constructor called for Animal" <<std::endl;
}

// Animal::Animal(std::string type) : type(type) {
// 	std::cout <<  "Default constructor called for " << this->type << "called" <<std::endl;
// }

Animal::Animal(const Animal &other){
	std::cout <<  "copy constructor called for Animal type" << this->type <<std::endl;
	*this = other;
}

Animal::~Animal(){
	std::cout <<  "Default destructor called for Animal" <<std::endl;
}

Animal &Animal::operator=(const Animal &other){
	std::cout <<  "copy assignment constructor called for Animal type" << this->type <<std::endl;
	if (this != &other){
		this->type = other.type;
	}
	return *this;
}

std::string Animal::getType() const{
	return (this->type);
}

void Animal::makeSound() const{
	std::cout <<  this->type << " makes sound muuuuuuuuuuuu" <<std::endl;
}
