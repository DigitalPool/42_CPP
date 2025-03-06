/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:33:13 by mac               #+#    #+#             */
/*   Updated: 2025/03/06 09:06:04 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename F>
void iter(T* array, size_t length, const F func) {
	for (size_t i = 0; i < length; i++) {
		func(array[i]);
	}
}

// void	iter(T *array, size_t arr_len, void (*foo)(T &))
// {
// 	if (array == NULL || foo == NULL)
// 		return ;
// 	for (size_t i = 0; i < arr_len; i++)
// 		foo(array[i]);
// }
#endif


