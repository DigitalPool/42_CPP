/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:31:44 by mac               #+#    #+#             */
/*   Updated: 2025/02/13 09:06:51 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain Default constructor called" << std::endl;
	// for (int i = 0; i < 100; i++) {
	// 	_ideas[i] = "Random idea #" + std::to_string(i);
	// }
}

Brain::Brain(const Brain &other) {
	*this = other;
	std::cout << "Brain Copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			if (other._ideas[i].length() > 0)
				this->_ideas[i].assign(other._ideas[i]);
			// this->_ideas[i] = other._ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain Destructor called" << std::endl;
}

const std::string	Brain::getIdea(int idea_idx) const {
	if (idea_idx < 100)
		return(this->_ideas[idea_idx]);
	else
		return ("\033[33mThere is only 100 ideas per brain.\033[0m");
}

const std::string *Brain::getIdeaAddress(size_t add) const {
	if (add < 100) {
		const std::string &stringREF = this->_ideas[add];
		return(&stringREF);
	}
	else
		return (NULL);
}

void	Brain::setIdea(int idea_idx, std::string idea)
{
	if (idea_idx < 100)
		this->_ideas[idea_idx] = idea;
	else
		std::cout << "\033[33mThere is only 100 ideas per brain.\033[0m" << std::endl;
}
