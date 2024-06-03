/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:55:46 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/03 15:57:50 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

WrongAnimal::WrongAnimal() : m_type("WrongAnimal") {
	return;
}

WrongAnimal::WrongAnimal(std::string type) : m_type(type) {
	return;
}

WrongAnimal::~WrongAnimal() {
	return;
}

WrongAnimal::WrongAnimal(const WrongAnimal& a) : m_type(a.m_type) {
	return;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& a) {
	m_type = a.m_type;
	return *this;
}

const std::string& WrongAnimal::getType() const {
	return m_type;
}

void WrongAnimal::makeSound() const {
	std::cout << "<dead silence>\n";
}
