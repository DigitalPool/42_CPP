/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:53:33 by mac               #+#    #+#             */
/*   Updated: 2025/02/06 23:03:09 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat(){
	this->type = "Cat";
	this->_brain = new Brain();
	std::cout << "Default constructor for Cat called" << std::endl;
}

Cat::~Cat(){
		delete _brain;
		std::cout << "Default destructor for Cat called" << std::endl;
}

Cat::Cat(const Cat &other){
	*this = other;
}

Cat &Cat::operator=(const Cat &other){
	if (this != &other)
		this->type = other.type;
	return *this;
}

std::string Cat::getType() const{
	return (this->type);
}

void Cat::makeSound() const{
	std::cout <<  this->type << " makes sound meoooooooow" <<std::endl;
}
