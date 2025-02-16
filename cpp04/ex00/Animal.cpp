/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:27:26 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/03 15:19:10 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <string>
#include <iostream>

Animal::Animal() : m_type("Animal") {
	return;
}

Animal::Animal(std::string type) : m_type(type) {
	return;
}

Animal::~Animal() {
	return;
}

Animal::Animal(const Animal& a) : m_type(a.m_type) {
	return;
}

Animal& Animal::operator=(const Animal& a) {
	m_type = a.m_type;
	return *this;
}

const std::string& Animal::getType() const {
	return m_type;
}

void Animal::makeSound() const {
	std::cout << "<dead silence>\n";
}
