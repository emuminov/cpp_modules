/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:41:53 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/04 15:00:12 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain() : m_ideas() {
	std::cout << "Brain constructor is called\n";
	return;
}

Brain::~Brain() {
	std::cout << "Brain destructor is called\n";
	return;
}

Brain::Brain(const Brain& a) {
	std::cout << "Brain copy constructor is called\n";
	*this = a;
}

Brain& Brain::operator=(const Brain& a) {
	std::cout << "Brain copy assign operator is called\n";
	for (int i = 0; i < 100; i++) {
		m_ideas[i] = a.m_ideas[i];
	}
	return *this;
}

const std::string& Brain::get_idea(int index) const {
	if (index < 0)
		index = 0;
	else if (index >= 100)
		index = 99;
	return m_ideas[index];
}

void Brain::set_idea(int index, std::string idea) {
	if (index < 0)
		index = 0;
	else if (index >= 100)
		index = 99;
	m_ideas[index] = idea;
}
