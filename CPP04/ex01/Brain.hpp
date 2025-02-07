/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:37:23 by mac               #+#    #+#             */
/*   Updated: 2025/02/06 22:48:09 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {

	protected:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain();

};

#endif
