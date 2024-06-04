/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:27:33 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/04 14:58:55 by emuminov         ###   ########.fr       */
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

Cat::Cat(const Cat& a) : m_type(a.m_type), m_brain(a.m_brain) {
	return;
}

Cat& Cat::operator=(const Cat& a) {
	m_type = a.m_type;
	*m_brain = *a.m_brain;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow\n";
}

const std::string& Cat::get_idea(int index) const {
	return m_brain->get_idea(index);
}

void Cat::set_idea(int index, std::string idea) {
	m_brain->set_idea(index, idea);
}
