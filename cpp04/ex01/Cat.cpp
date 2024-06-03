/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:27:33 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/03 19:02:51 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat() : Animal("Cat"), m_brain(new Brain) {
	return;
}

Cat::~Cat() {
	delete m_brain;
	return;
}

Cat::Cat(const Cat& a) : m_type(a.m_type) {
	return;
}

Cat& Cat::operator=(const Cat& a) {
	m_type = a.m_type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow\n";
}

const std::string& Cat::get_idea(int index) const {
	if (index < 0)
		index = 0;
	else if (index >= 100)
		index = 99;
	return m_brain->ideas[index];
}

void Cat::set_idea(int index, std::string idea) {
	if (index < 0)
		index = 0;
	else if (index >= 100)
		index = 99;
	m_brain->ideas[index] = idea;
}
