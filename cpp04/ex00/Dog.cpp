/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:27:36 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/04 15:59:38 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog constructor is called\n";
	return;
}

Dog::~Dog() {
	std::cout << "Dog destructor is called\n";
	return;
}

Dog::Dog(const Dog& a) : m_type(a.m_type) {
	std::cout << "Dog copy constructor is called\n";
	return;
}

Dog& Dog::operator=(const Dog& a) {
	std::cout << "Dog copy assign operator is called\n";
	m_type = a.m_type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "BARK BARK BARK!!!\n";
}
