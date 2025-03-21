/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:01:51 by mac               #+#    #+#             */
/*   Updated: 2025/03/17 16:26:53 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <list>
#include <vector>
#include <iostream>

class PmergeMe {
public:
    // Constructs the object by copying the input numbers into two containers.
    PmergeMe(const std::vector<int>& numbers);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    // Sorts the containers, measures and prints the sorting time and results.
    void sort();

private:
    std::deque<int> _deque;
    std::list<int> _list;

    // Sorting algorithms for each container.
    void mergeInsertionSortDeque(std::deque<int>& d);
    void mergeInsertionSortList(std::list<int>& l);

    // Merge functions for each container.
    void mergeDeque(std::deque<int>& left, std::deque<int>& right, std::deque<int>& result);
    std::list<int> mergeList(const std::list<int>& left, const std::list<int>& right);

    // Insertion sort functions for small subranges.
    void insertionSortDeque(std::deque<int>& d, int left, int right);
    void insertionSortList(std::list<int>& l);
};

#endif
