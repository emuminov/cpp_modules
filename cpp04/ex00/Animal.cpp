/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:27:26 by emuminov          #+#    #+#             */
/*   Updated: 2024/07/24 14:06:32 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <string>
#include <iostream>

Animal::Animal() : m_type("Animal") {
	std::cout << "Animal constructor is called\n";
	return;
}

Animal::Animal(std::string type) : m_type(type) {
	std::cout << "Protected Animal constructor is called\n";
	return;
}

Animal::~Animal() {
	std::cout << "Animal destructor is called\n";
	return;
}

Animal::Animal(const Animal& a) : m_type(a.m_type) {
	std::cout << "Animal copy constructor is called\n";
	return;
}

Animal& Animal::operator=(const Animal& a) {
	std::cout << "Animal copy assign operator is called\n";
	if (this != &a)
		m_type = a.m_type;
	return *this;
}

const std::string& Animal::getType() const {
	return m_type;
}

void Animal::makeSound() const {
	std::cout << "<dead silence>\n";
}
