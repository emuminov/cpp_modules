/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:39:11 by emuminov          #+#    #+#             */
/*   Updated: 2024/07/18 18:17:39 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : _raw(0) {
    std::cout << "Default constructor called\n";
    return;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called\n";
    return;
}

Fixed::Fixed(const Fixed& f) {
    std::cout << "Copy constructor called\n";
    *this = f;
    return;
}

Fixed& Fixed::operator=(const Fixed& f) {
    std::cout << "Copy assignment operator called\n";
    if (this != &f)
        _raw = f.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called\n";
    return _raw;
}

void Fixed::setRawBits(int raw) { _raw = raw; }
