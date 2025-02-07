/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:25:54 by mac               #+#    #+#             */
/*   Updated: 2025/02/06 21:50:26 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main() {

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* merin = new WrongAnimal();
	const WrongAnimal* h = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << h->getType() << " " << std::endl;
	std::cout << merin->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	h->makeSound();
	merin->makeSound();
	meta->makeSound();

	delete(h);
	delete(i);
	delete(j);
	delete(meta);
	delete(merin);
	return 0;
}
