/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:19:05 by mac               #+#    #+#             */
/*   Updated: 2025/01/15 12:55:44 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// The new keyword performs the following actions: Allocates Memory: It dynamically
// allocates memory for an object of the specified type (Zombie in this case) on the heap.
// Unlike stack memory, heap memory is not automatically managed and must be explicitly
// freed. Invokes the Constructor: After allocating memory, new calls the constructor of
// the object and initializes it with the provided arguments (name in this case). Returns
// a Pointer: The new keyword returns a pointer to the newly created object in heap memory.

// If you create an object without using new, it is allocated on the stack

Zombie* newZombie( std::string name ){
	Zombie* ptrZombie;
	ptrZombie = new Zombie(name);

	return ptrZombie;
}
