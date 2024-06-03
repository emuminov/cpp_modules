/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:27:36 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/03 14:54:00 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
	return;
}

Dog::~Dog() {
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
