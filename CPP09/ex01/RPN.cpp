/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:21:47 by mac               #+#    #+#             */
/*   Updated: 2025/03/17 16:17:13 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <cstdlib>

RPN::RPN() { }

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN &RPN::operator=(const RPN &other) {
	(void)other;
	return *this;
}

RPN::~RPN() { }

int RPN::evaluate(const std::string &expression) {
	std::istringstream iss(expression);
	std::stack<int> stack;
	std::string token;

	// we use a stream extraction operator to read tokens from the input string.
	// we then process each token according to its type.
	// if the token is an operator, we apply it to the top two numbers on the stack.
	// if the token is a concatenated token, we split it into a number part and an operator.
	// we then process the number part as a number token and the operator part as an operator token.
	// if the token is a number, we convert it to an integer and push it on the stack.
	// if the token is not an operator, a concatenated token, or a number, we throw an exception.
	// if the stack has more than one number left after processing all tokens, we throw an exception.
	// otherwise, we return the single number left on the stack.
	while (iss >> token) {
		if (isOperatorToken(token)) {
			processOperatorToken(token, stack);
		} else if (isConcatenatedToken(token)) {
			processConcatenatedToken(token, stack);
		} else {
			processNumberToken(token, stack);
		}
	}

	if (stack.size() != 1)
		throw std::runtime_error("Error");
	return stack.top();
}

bool RPN::isOperatorToken(const std::string &token) {
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isConcatenatedToken(const std::string &token) {
	if (token.size() > 1) {
		char lastChar = token.back();
		return (lastChar == '+' || lastChar == '-' || lastChar == '*' || lastChar == '/');
	}
	return false;
}

void RPN::processOperatorToken(const std::string &token, std::stack<int> &stack) {
	if (stack.size() < 2)
		throw std::runtime_error("Error");
	int b = stack.top();
	stack.pop();
	int a = stack.top();
	stack.pop();

	int result = applyOperator(token[0], a, b);
	stack.push(result);
}

void RPN::processConcatenatedToken(const std::string &token, std::stack<int> &stack) {
	std::string numberPart = token.substr(0, token.size() - 1);
	char op = token.back();

	int number = std::stoi(numberPart);
	stack.push(number);

	processOperatorToken(std::string(1, op), stack);
}

void RPN::processNumberToken(const std::string &token, std::stack<int> &stack) {
	try {
		int number = std::stoi(token);
		stack.push(number);
	} catch (...) {
		throw std::runtime_error("Error");
	}
}

int RPN::applyOperator(char op, int a, int b) {
	switch (op) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/':
			if (b == 0)
				throw std::runtime_error("Error");
			return a / b;
		default:
			throw std::runtime_error("Error");
	}
}
