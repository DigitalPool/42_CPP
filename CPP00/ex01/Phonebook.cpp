/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:35:24 by mac               #+#    #+#             */
/*   Updated: 2025/01/08 20:32:12 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

PhoneBook::PhoneBook() : list_count(0) {

}

PhoneBook::~PhoneBook(){

}

void print_truncated(const std::string& text) {
	if (text.length() > 10)
		std::cout << std::setw(10) << std::right << text.substr(0, 9) + ".";
	else
		std::cout << std::setw(10) << std::right << text;
}

void PhoneBook::displayContacts() const {
	if (list_count == 0) {
		std::cout << "The phonebook is empty. No contacts to display.\n";
		return;
	}

	std::cout << "|" << std::setw(10) << "Index"
			  << "|" << std::setw(10) << "First Name"
			  << "|" << std::setw(10) << "Last Name"
			  << "|" << std::setw(10) << "Nickname" << "|\n";
	std::cout << "---------------------------------------------\n";

	for (int i = 0; i < list_count; i++) {
		std::cout << "|" << std::setw(10) << std::right << contacts[i].getIndex() << "|";
		print_truncated(contacts[i].getFirstName());
		std::cout << "|";
		print_truncated(contacts[i].getLastName());
		std::cout << "|";
		print_truncated(contacts[i].getNickName());
		std::cout << "|\n";
	}
}

void PhoneBook::searchContacts() const {
	if (list_count == 0) {
		std::cout << "The phonebook is empty. No contacts to search.\n";
		return;
	}

	displayContacts();

	std::cout << "Enter the contact index: ";
	std::string input;
	int contact_index;

	while (true) {
		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof()) {
			std::cout << "\nEOF detected. Exiting program.\n";
			exit(0);
			}
		}
		try {
			contact_index = std::stoi(input);
		} catch (std::invalid_argument&) {
			std::cout << "Invalid index. Please enter a valid number: ";
			continue;
		}

		if (contact_index < 1 || contact_index > list_count) {
			std::cout << "Invalid contact index. Please enter a number between 1 and " << list_count << ": ";
		} else {
			const Contact& c = contacts[contact_index - 1];
			std::cout << "|" << std::setw(10) << std::right << c.getIndex() << "|";
			print_truncated(c.getFirstName());
			std::cout << "|";
			print_truncated(c.getLastName());
			std::cout << "|";
			print_truncated(c.getNickName());
			std::cout << "|" << std::endl;
			break;
		}
	}
}

void PhoneBook::addContact() {
	Contact new_contact;
	std::string input;

	if (list_count == 8) {
		for (int i = 1; i < 8; i++) {
			contacts[i - 1] = contacts[i];
			contacts[i - 1].setIndex(i);
		}
		list_count--;
	}

	new_contact.setIndex(list_count + 1);

	std::cout << "First name: ";
	while (std::getline(std::cin, input) && input.empty())
		std::cout << "Field cannot be empty. First name: ";
	new_contact.setFirstName(input);

	std::cout << "Last name: ";
	while (std::getline(std::cin, input) && input.empty())
		std::cout << "Field cannot be empty. Last name: ";
	new_contact.setLastName(input);

	std::cout << "Nickname: ";
	while (std::getline(std::cin, input) && input.empty())
		std::cout << "Field cannot be empty. Nickname: ";
	new_contact.setNickName(input);

	std::cout << "Phone number: ";
	while (std::getline(std::cin, input) && input.empty())
		std::cout << "Field cannot be empty. Phone number: ";
	new_contact.setPhoneNumber(input);

	std::cout << "Darkest secret: ";
	while (std::getline(std::cin, input) && input.empty())
		std::cout << "Field cannot be empty. Darkest secret: ";
	new_contact.setDarkSecret(input);

	contacts[list_count++] = new_contact;
}

int main() {
	PhoneBook phonebook;
	std::string command;

	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command)) {
			if (std::cin.eof()) {
				std::cout << "\nEOF detected. Exiting program.\n";
				exit(0);
			}
			std::cin.clear();
			std::cout << "Input error. Please try again.\n";
			continue;
		}

		if (command == "ADD") {
			phonebook.addContact();
		} else if (command == "SEARCH") {
			phonebook.searchContacts();
		} else if (command == "EXIT") {
			break;
		} else {
			std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT.\n";
		}
	}
	return 0;
}
