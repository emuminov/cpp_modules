/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:27:33 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/04 16:00:02 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat constructor is called\n";
	return;
}

Cat::~Cat() {
	std::cout << "Cat destructor is called\n";
	return;
}

Cat::Cat(const Cat& a) : m_type(a.m_type) {
	std::cout << "Cat copy constructor is called\n";
	return;
}

Cat& Cat::operator=(const Cat& a) {
	std::cout << "Cat copy assign operator is called\n";
	m_type = a.m_type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow\n";
}
