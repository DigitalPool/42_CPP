/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:01:51 by mac               #+#    #+#             */
/*   Updated: 2025/03/05 22:19:55 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include <stack>

int main() {
    // Create a MutantStack of ints.
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    // Print top element.
    std::cout << "Top: " << mstack.top() << std::endl;

    // Remove the top element.
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    // Push more numbers.
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Iterate through the MutantStack.
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    std::cout << "MutantStack contents:" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    // Copy to a std::stack.
    std::stack<int> s(mstack);

    return 0;
}
