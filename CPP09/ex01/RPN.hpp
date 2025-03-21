/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:21:01 by mac               #+#    #+#             */
/*   Updated: 2025/03/17 10:26:57 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN {
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();
		
		int evaluate(const std::string &expression);
		bool isOperatorToken(const std::string &token);
		bool isConcatenatedToken(const std::string &token);
		void processOperatorToken(const std::string &token, std::stack<int> &stack);
		void processConcatenatedToken(const std::string &token, std::stack<int> &stack);
		void processNumberToken(const std::string &token, std::stack<int> &stack);
		int applyOperator(char op, int a, int b);
};

#endif
