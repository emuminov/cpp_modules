/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:27:36 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/04 14:08:36 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog"), m_brain(new Brain) {
	return;
}

Dog::~Dog() {
	delete m_brain;
	return;
}

Dog::Dog(const Dog& a) : m_type(a.m_type) {
	return;
}

Dog& Dog::operator=(const Dog& a) {
	m_type = a.m_type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "BARK BARK BARK!!!\n";
}

const std::string& Dog::get_idea(int index) const {
	return m_brain->get_idea(index);
}

void Dog::set_idea(int index, std::string idea) {
	m_brain->set_idea(index, idea);
}
