/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:53:33 by mac               #+#    #+#             */
/*   Updated: 2025/02/13 09:01:11 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal(){
	std::cout << "Default constructor for Dog called" << std::endl;
	this->type = "Dog";
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		perror("allocation failed for Dog brain");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
}

Dog::Dog(const Dog &other) : Animal(){
	std::cout << "Copy Constructor for Dog called" << std::endl;
	*this = other;
}

Dog::~Dog(){
		delete this->_brain;
		std::cout << "Default destructor for Dog called" << std::endl;
}
// Dog::Dog() {
// 	this->type = "Dog";
// 	this->_brain = new Brain();
// 	std::cout << "Default constructor for Dog called" << std::endl;
// }

// Dog::~Dog(){
// 		delete _brain;
// 		std::cout << "Default destructor for Dog called" << std::endl;
// }

// Dog::Dog(const Dog &other) : Animal(other) {
// 	*this = other;
// 	std::cout << "Dog Copy constructor called" << std::endl;
// }

Dog &Dog::operator=(const Dog &other){
	std::cout << "Copy assignment operator for Dog called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		this->_brain = other._brain;
		if (this->_brain == NULL)
		{
			perror("alloDogion failed for Dog brain");
			std::cerr << "Exiting the process now." << std::endl;
			exit(1);
		}
	}
	*this->_brain = *other._brain;
	return *this;
}

// Dog &Dog::operator=(const Dog &other){
// 	std::cout << "Dog Copy assignment operator called" << std::endl;
// 	if (this != &other)
// 		this->type = other.type;
// 	return *this;
// }

std::string Dog::getType() const{
	return (this->type);
}

void Dog::makeSound() const{
	std::cout <<  this->type << " makes sound baaaaaaaark" <<std::endl;
}

void	Dog::getIdeas(void)const
{
	for (int i = 0; i < 3; i++)
		std::cout << "\tIdea " << i << " of the Dog is: \"" << this->_brain->getIdea(i) << "\" at the address " << this->_brain->getIdeaAddress(i) << std::endl;
}

void Dog::setIdeas(size_t idea_idx, std::string idea)
{
		this->_brain->setIdea(idea_idx, idea);
}
