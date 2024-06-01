/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:39:11 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/01 16:44:06 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed(void) : _raw(0) {
    std::cout << "Default constructor called\n";
    return;
}

Fixed::Fixed(const int nbr) : _raw(nbr << scale) {
    std::cout << "Int constructor called\n";
    return;
}

Fixed::Fixed(const float nbr) : _raw(roundf(nbr * (1 << scale))) {
    std::cout << "Float constructor called\n";
    return;
}

Fixed::~Fixed(void) { return; }

Fixed::Fixed(const Fixed& f) : _raw(f._raw) {
    std::cout << "Copy constructor called\n";
    return;
}

Fixed& Fixed::operator=(const Fixed& f) {
    std::cout << "Copy assignment operator called\n";
    this->_raw = f.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const { return this->_raw; }

void Fixed::setRawBits(int raw) { this->_raw = raw; }

float Fixed::toFloat(void) const { return (float)this->_raw / (1 << scale); }

int Fixed::toInt(void) const { return this->_raw >> scale; }

std::ostream& operator<<(std::ostream& out, const Fixed& f) {
    out << f.toFloat();
    return out;
}
