/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:55:43 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/04 16:03:19 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat constructor is called\n";
	return;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor is called\n";
	return;
}

WrongCat::WrongCat(const WrongCat& a) : m_type(a.m_type) {
	std::cout << "WrongCat copy constructor is called\n";
	return;
}

WrongCat& WrongCat::operator=(const WrongCat& a) {
	std::cout << "WrongCat copy assign operator is called\n";
	m_type = a.m_type;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Meow\n";
}
