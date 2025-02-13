/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:53:33 by mac               #+#    #+#             */
/*   Updated: 2025/02/13 08:51:18 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() : Animal(){
	std::cout << "Default constructor for Cat called" << std::endl;
	this->type = "Cat";
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		perror("allocation failed for cat brain");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
}

Cat::Cat(const Cat &other) : Animal(){
	std::cout << "Copy Constructor for Cat called" << std::endl;
	*this = other;
}

Cat::~Cat(){
		delete this->_brain;
		std::cout << "Default destructor for Cat called" << std::endl;
}

Cat &Cat::operator=(const Cat &other){
	std::cout << "Copy assignment operator for Cat called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		this->_brain = other._brain;
		if (this->_brain == NULL)
		{
			perror("allocation failed for cat brain");
			std::cerr << "Exiting the process now." << std::endl;
			exit(1);
		}
	}
	*this->_brain = *other._brain;
	return *this;
}

std::string Cat::getType() const{
	return (this->type);
}

void Cat::makeSound() const{
	std::cout <<  this->type << " makes sound meoooooooow" <<std::endl;
}

// Getter
void Cat::getIdeas() const
{
	for (int i = 0; i < 3; i++)
		std::cout << "\tIdea " << i << " of the Cat is: \"" << this->_brain->getIdea(i) << "\" at the address " << this->_brain->getIdeaAddress(i) << std::endl;
}

// Setter
void Cat::setIdeas(size_t idea_idx, std::string idea)
{
		this->_brain->setIdea(idea_idx, idea);
}
