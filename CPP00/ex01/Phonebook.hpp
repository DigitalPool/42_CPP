/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 05:35:09 by mac               #+#    #+#             */
/*   Updated: 2025/01/08 13:18:04 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8];
	int list_count;

public:
	PhoneBook(void);
	~PhoneBook(void);

	void addContact();
	void searchContacts() const;
	void displayContacts() const;
};


#endif

