/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:37:23 by mac               #+#    #+#             */
/*   Updated: 2025/02/13 08:31:01 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {

	protected:
		std::string _ideas[100];

	public:
		Brain();
		Brain(const Brain &other);
		~Brain();
		Brain &operator=(const Brain &other);

		const std::string getIdea(int idea_idx)const;
		const std::string *getIdeaAddress(size_t add)const;
		void setIdea(int idea_idx, std::string idea);
};

#endif
