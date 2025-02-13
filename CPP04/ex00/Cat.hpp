/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:50:43 by mac               #+#    #+#             */
/*   Updated: 2025/02/13 08:09:37 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal{

	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat &other);
		virtual ~Cat();
		Cat &operator=(const Cat &other);

		std::string getType() const;
		virtual void makeSound() const;
};

#endif
