/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:50:43 by mac               #+#    #+#             */
/*   Updated: 2025/02/06 19:39:13 by mac              ###   ########.fr       */
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
		Cat &operator=(const Cat &other);

		virtual ~Cat();

		std::string getType() const;
		virtual void makeSound() const;
};

#endif
