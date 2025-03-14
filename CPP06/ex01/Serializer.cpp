/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:54:58 by mac               #+#    #+#             */
/*   Updated: 2025/03/05 19:03:52 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}


Serializer::Serializer() {
}

Serializer::~Serializer() {
}

Serializer::Serializer(const Serializer& other) {
	*this = other;
}

Serializer& Serializer::operator=(const Serializer& other) {
	(void) other;
	return *this;
}
