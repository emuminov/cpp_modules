/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:41:53 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/03 18:52:40 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : ideas() {
	return;
}

Brain::~Brain() {
	return;
}

Brain::Brain(const Brain& a) {
	*this = a;
}

Brain& Brain::operator=(const Brain& a) {
	for (int i = 0; i < 100; i++) {
		ideas[i] = a.ideas[i];
	}
	return *this;
}
