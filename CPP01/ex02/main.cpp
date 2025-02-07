/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:36:08 by mac               #+#    #+#             */
/*   Updated: 2025/01/15 23:25:06 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void){
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << "The address of the string: " << &string << std::endl;
	std::cout << "memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << "The value of the string: " << string << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
}

