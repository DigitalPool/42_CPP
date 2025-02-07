/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 05:35:09 by mac               #+#    #+#             */
/*   Updated: 2025/01/08 13:48:22 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>

class Contact {
private:
	int index;
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string dark_secret;

public:
	Contact();
	~Contact();

	// Getters (Accessors)
	int getIndex() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getPhoneNumber() const;
	std::string getDarkSecret() const;

	// Setters (Mutators)
	void setIndex(int idx);
	void setFirstName(const std::string& name);
	void setLastName(const std::string& name);
	void setNickName(const std::string& name);
	void setPhoneNumber(const std::string& number);
	void setDarkSecret(const std::string& secret);
};

#endif

