/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:27:33 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/04 15:54:04 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat() : Animal("Cat"), m_brain(new Brain) {
	std::cout << "Cat constructor is called\n";
	return;
}

Cat::~Cat() {
	std::cout << "Cat destructor is called\n";
	delete m_brain;
	return;
}

Cat::Cat(const Cat& a) : m_type(a.m_type), m_brain(new Brain(*a.m_brain)) {
	std::cout << "Cat copy constructor is called\n";
	return;
}

Cat& Cat::operator=(const Cat& a) {
	std::cout << "Cat copy assign operator is called\n";
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
