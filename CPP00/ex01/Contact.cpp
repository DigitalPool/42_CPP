/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:20:44 by mac               #+#    #+#             */
/*   Updated: 2025/01/08 13:44:30 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact():index(0), first_name(""), last_name(""), nick_name(""),
					phone_number(""), dark_secret(""){

}

Contact::~Contact(){

}

//getters
int Contact::getIndex() const { return index; }
std::string Contact::getFirstName() const { return first_name; }
std::string Contact::getLastName() const { return last_name; }
std::string Contact::getNickName() const { return nick_name; }
std::string Contact::getPhoneNumber() const { return phone_number; }
std::string Contact::getDarkSecret() const { return dark_secret; }

//setters
void Contact::setIndex(int idx) { index = idx; }
void Contact::setFirstName(const std::string& name) { first_name = name; }
void Contact::setLastName(const std::string& name) { last_name = name; }
void Contact::setNickName(const std::string& name) { nick_name = name; }
void Contact::setPhoneNumber(const std::string& number) { phone_number = number; }
void Contact::setDarkSecret(const std::string& secret) { dark_secret = secret; }
