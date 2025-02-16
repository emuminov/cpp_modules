/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:55:43 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/03 15:59:48 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	return;
}

WrongCat::~WrongCat() {
	return;
}

WrongCat::WrongCat(const WrongCat& a) : m_type(a.m_type) {
	return;
}

WrongCat& WrongCat::operator=(const WrongCat& a) {
	m_type = a.m_type;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Meow\n";
}
