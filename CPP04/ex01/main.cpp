/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:25:54 by mac               #+#    #+#             */
/*   Updated: 2025/02/06 23:08:56 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

// #include "Animal.hpp"
// #include "Cat.hpp"
// #include "Dog.hpp"
// #include "WrongAnimal.hpp"
// #include "WrongCat.hpp"
// #include "Brain.hpp"

// int main()
// {
// 	std::cout << "\033[34mConstructing\033[0m" << std::endl;
// 	const Animal	*meta[10];
// 	for (int i = 0; i < 10; i++)
// 	{
// 		if (i % 2)
// 		{
// 			meta[i] = new Cat();
// 			if (meta[i] == NULL)
// 			{
// 				perror("Cat allocation failed");
// 				std::cerr << "Exiting process now";
// 				exit(1);
// 			}
// 		}
// 		else
// 		{
// 			meta[i] = new Dog();
// 			if (meta[i] == NULL)
// 			{
// 				perror("Dog allocation failed");
// 				std::cerr << "Exiting process now";
// 				exit(1);
// 			}
// 		}
// 	}
// 	std::cout << std::endl;

// 	std::cout << "\033[34mTesting\033[0m" << std::endl;
// 	for (int i = 0; i < 10; i++)
// 	{
// 		std::cout << std::endl;
// 		std::cout << "Animal _type: " << meta[i]->getType() << std::endl;
// 		meta[i]->makeSound();
// 		std::cout << std::endl;
// 	}
// 	std::cout << std::endl;

// 	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
// 	for (int i = 0; i < 10; i++)
// 		delete(meta[i]);

// //THIS PART IS FOR TESTING DEEP COPY ↓

// 	std::cout << std::endl << std::endl;
// 	std::cout << "#### showing that the copy constructor creates a deep copy ####" << std::endl;
// 	std::cout << std::endl;

// 	std::cout << "\033[34mConstructing\033[0m" << std::endl;
// 	Dog *a = new Dog();
// 	// Cat *a = new Cat();
// 	if (a == NULL)
// 	{
// 		perror("Allocation failed");
// 		std::cerr << "Exiting the process now." << std::endl;
// 		exit(1);
// 	}

// 	// a->setIdea(0, "I have to sniff it");
// 	// a->setIdea(1, "I have to pee on it");
// 	// a->setIdea(2, "I have to sniff it again");
// 	// a->setIdea(101, "some shit");

// 	Dog *b = new Dog(*a);
// 	// Cat *b = new Cat(*a);
// 	if (b == NULL)
// 	{
// 		perror("Allocation failed");
// 		std::cerr << "Exiting the process now." << std::endl;
// 		exit(1);
// 	}
// 	std::cout << std::endl;

// 	std::cout << "\033[34mTesting a\033[0m" << std::endl;
// 	std::cout << "The " << a->getType() << " a has the following ideas: " << std::endl;
// 	// a->getIdeas();
// 	std::cout << std::endl;

// 	std::cout << "\033[34mDeconstructing a\033[0m" << std::endl;
// 	delete(a);
// 	std::cout << std::endl;

// 	std::cout << "\033[34mTesting b\033[0m" << std::endl;
// 	std::cout << "The " << b->getType() << " b has the following ideas: " << std::endl;
// 	// b->getIdeas();
// 	std::cout << std::endl;

// 	std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
// 	delete(b);

// 	return (0);
// }

int main() {
	const int SIZE = 100;
	Animal* animals[SIZE];

	for (int i = 0; i < SIZE; i++) {
		if (i < (SIZE / 2)) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
	}

	for (int i = 0; i < SIZE; i++) {
		delete (animals[i]);
	}
	return 0;
}

// int main() {

// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	const WrongAnimal* merin = new WrongAnimal();
// 	const WrongAnimal* h = new WrongCat();

// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	std::cout << h->getType() << " " << std::endl;
// 	std::cout << merin->getType() << " " << std::endl;

// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	h->makeSound();
// 	merin->makeSound();
// 	meta->makeSound();

// 	delete(h);
// 	delete(i);
// 	delete(j);
// 	delete(meta);
// 	delete(merin);
// 	return 0;
// }
