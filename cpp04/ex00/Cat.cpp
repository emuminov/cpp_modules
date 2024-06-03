/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:27:33 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/03 16:17:47 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
	return;
}

Cat::~Cat() {
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
