/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:01:51 by mac               #+#    #+#             */
/*   Updated: 2025/03/17 16:58:17 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <ctime>
#include <stdexcept>

// Constructor: Fill both containers with the input numbers.
PmergeMe::PmergeMe(const std::vector<int>& numbers) {
	for (size_t i = 0; i < numbers.size(); i++) {
		_deque.push_back(numbers[i]);
		_list.push_back(numbers[i]);
	}
}

PmergeMe::PmergeMe(const PmergeMe &other) : _deque(other._deque), _list(other._list) { }

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_deque = other._deque;
		_list = other._list;
	}
	return *this;
}

PmergeMe::~PmergeMe() { }

// sort() – performs sorting on both containers, measures the time, and displays results.
void PmergeMe::sort() {
	// Copy containers so that we preserve the original unsorted data.
	std::deque<int> d = _deque;
	std::list<int> l = _list;

	clock_t start = clock();
	mergeInsertionSortDeque(d);
	clock_t end = clock();
	// Calculate time in microseconds.
	double diffDeque = 1000000.0 * (end - start) / CLOCKS_PER_SEC;

	start = clock();
	mergeInsertionSortList(l);
	end = clock();
	double diffList = 1000000.0 * (end - start) / CLOCKS_PER_SEC;

	// Display the sorted sequence from the deque.
	std::cout << "After: ";
	for (std::deque<int>::iterator it = d.begin(); it != d.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// Display timing results.
	std::cout << "Time to process a range of " << d.size()
			  << " elements with std::deque : " << diffDeque << " us" << std::endl;
	std::cout << "Time to process a range of " << l.size()
			  << " elements with std::list  : " << diffList << " us" << std::endl;
}

// ----------------------- Deque Sorting Functions ---------------------------

// mergeInsertionSortDeque: Recursively sorts the deque using a merge sort approach,
// switching to insertion sort when the range is small.
void PmergeMe::mergeInsertionSortDeque(std::deque<int>& d) {
	if (d.size() <= 1)
		return;
	if (d.size() < 10) {  // Threshold for using insertion sort.
		insertionSortDeque(d, 0, d.size() - 1);
		return;
	}

	std::deque<int> left, right;
	size_t mid = d.size() / 2;
	for (size_t i = 0; i < mid; i++) {
		left.push_back(d[i]);
	}
	for (size_t i = mid; i < d.size(); i++) {
		right.push_back(d[i]);
	}
	mergeInsertionSortDeque(left);
	mergeInsertionSortDeque(right);
	mergeDeque(left, right, d);
}

// mergeDeque: Merges two sorted deques into a single sorted deque.
void PmergeMe::mergeDeque(std::deque<int>& left, std::deque<int>& right, std::deque<int>& result) {
	result.clear();
	size_t i = 0, j = 0;
	while (i < left.size() && j < right.size()) {
		if (left[i] <= right[j]) {
			result.push_back(left[i]);
			i++;
		} else {
			result.push_back(right[j]);
			j++;
		}
	}
	while (i < left.size()) {
		result.push_back(left[i]);
		i++;
	}
	while (j < right.size()) {
		result.push_back(right[j]);
		j++;
	}
}

// insertionSortDeque: A simple insertion sort for a subrange of the deque.
void PmergeMe::insertionSortDeque(std::deque<int>& d, int left, int right) {
	int i, j, key;
	for (i = left + 1; i <= right; i++) {
		key = d[i];
		j = i - 1;
		while (j >= left && d[j] > key) {
			d[j + 1] = d[j];
			j--;
		}
		d[j + 1] = key;
	}
}

// ----------------------- List Sorting Functions ---------------------------

// mergeInsertionSortList: Recursively sorts the list using a merge sort approach,
// switching to insertion sort when the range is small.
void PmergeMe::mergeInsertionSortList(std::list<int>& l) {
	if (l.size() <= 1)
		return;
	if (l.size() < 10) {
		insertionSortList(l);
		return;
	}

	std::list<int> left, right;
	std::list<int>::iterator it = l.begin();
	size_t mid = l.size() / 2;
	for (size_t i = 0; i < mid; i++) {
		left.push_back(*it);
		++it;
	}
	for (; it != l.end(); ++it) {
		right.push_back(*it);
	}
	mergeInsertionSortList(left);
	mergeInsertionSortList(right);
	l = mergeList(left, right);
}

// mergeList: Merges two sorted lists and returns the resulting sorted list.
std::list<int> PmergeMe::mergeList(const std::list<int>& left, const std::list<int>& right) {
	std::list<int> result;
	std::list<int>::const_iterator itLeft = left.begin();
	std::list<int>::const_iterator itRight = right.begin();
	while (itLeft != left.end() && itRight != right.end()) {
		if (*itLeft <= *itRight) {
			result.push_back(*itLeft);
			++itLeft;
		} else {
			result.push_back(*itRight);
			++itRight;
		}
	}
	while (itLeft != left.end()) {
		result.push_back(*itLeft);
		++itLeft;
	}
	while (itRight != right.end()) {
		result.push_back(*itRight);
		++itRight;
	}
	return result;
}

// insertionSortList: A simple insertion sort for a list.
// For simplicity, we build a new sorted list by inserting elements in order.
void PmergeMe::insertionSortList(std::list<int>& l) {
	if (l.empty())
		return;
	std::list<int> sorted;
	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) {
		bool inserted = false;
		for (std::list<int>::iterator sit = sorted.begin(); sit != sorted.end(); ++sit) {
			if (*it < *sit) {
				sorted.insert(sit, *it);
				inserted = true;
				break;
			}
		}
		if (!inserted)
			sorted.push_back(*it);
	}
	l = sorted;
}
