/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:01:51 by mac               #+#    #+#             */
/*   Updated: 2025/03/05 19:04:37 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main() {
	Data data;
	data.number = 42;
	data.text = "Hello, Serialization!";

	uintptr_t serialized = Serializer::serialize(&data);
	Data* deserialized = Serializer::deserialize(serialized);

	std::cout << "Original pointer:		" << &data << std::endl;
	std::cout << "Serialized value:		" << serialized << std::endl;
	std::cout << "Deserialized pointer: " << deserialized << std::endl;

	if (deserialized == &data)
		std::cout << "Success: The deserialized pointer matches the original pointer." << std::endl;
	else
		std::cout << "Failure: The deserialized pointer does not match the original pointer." << std::endl;

	return 0;
}


// int main()
// {
// 	Data ptr2;
// 	ptr2.text = "Michaela Mustermann";
// 	ptr2.number = 42;
// 	// ptr2.next = NULL;

// 	Data ptr;
// 	ptr.text = "Max Mustermann";
// 	ptr.number = 42;
// 	// ptr.next = &ptr2;


// 	std::cout << "Here is the original structs:" <<
// 				"\n\taddress: " << &ptr <<
// 				"\n\ttext: " << ptr.text <<
// 				"\n\tnumber: " << ptr.number <<
// 				// "\n\taddress next: " << ptr.next <<
// 	std::endl;
// 	std::cout << "\taddress ptr2: " << &ptr2 <<
// 				"\n\ttext: " << ptr2.text <<
// 				"\n\tnumber: " << ptr2.number <<
// 				// "\n\taddress next: " << ptr2.next <<
// 	std::endl << std::endl;

// 	Serializer a;

// 	Data *reserialized_struct = a.deserialize(a.serialize(&ptr));

// 	std::cout << "Here is the reserialized structs:" <<
// 				"\n\taddress: " << reserialized_struct <<
// 				"\n\ttext: " << reserialized_struct->text <<
// 				"\n\tnumber: " << reserialized_struct->number <<
// 				// "\n\taddress next: " << reserialized_struct->next <<
// 	std::endl;
// 	std::cout << "\taddress ptr2: " << &ptr2 <<
// 				"\n\ttext: " << ptr2.text <<
// 				"\n\tnumber: " << ptr2.number <<
// 				// "\n\taddress next: " << ptr2.next <<
// 	std::endl << std::endl;

// 	return (0);
// }
