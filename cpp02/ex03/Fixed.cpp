/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:39:11 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/11 22:03:37 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed(void) : _raw(0) { return; }

Fixed::Fixed(const int nbr) : _raw(nbr << scale) { return; }

Fixed::Fixed(const float nbr) : _raw(roundf(nbr * (1 << scale))) { return; }

Fixed::~Fixed(void) { return; }

Fixed::Fixed(const Fixed& f) : _raw(f._raw) {
    return;
}

Fixed& Fixed::operator=(const Fixed& f) {
    this->_raw = f._raw;
    return (*this);
}

bool Fixed::operator>(const Fixed& f) const { return this->_raw > f._raw; }

bool Fixed::operator<(const Fixed& f) const { return this->_raw < f._raw; }

bool Fixed::operator>=(const Fixed& f) const { return this->_raw >= f._raw; }

bool Fixed::operator<=(const Fixed& f) const { return this->_raw <= f._raw; }

bool Fixed::operator==(const Fixed& f) const { return this->_raw == f._raw; }

bool Fixed::operator!=(const Fixed& f) const { return this->_raw != f._raw; }

Fixed Fixed::operator+(const Fixed& f) const {
	Fixed result(0);
	result._raw = this->_raw + f._raw;
    return result;
}

Fixed Fixed::operator-(const Fixed& f) const {
	Fixed result(0);
	result._raw = this->_raw - f._raw;
    return result;
}

Fixed Fixed::operator*(const Fixed& f) const {
	Fixed result(0);
	result._raw = this->_raw * f._raw;
    return result;
}

Fixed Fixed::operator/(const Fixed& f) const {
	Fixed result(0);
	result._raw = this->_raw / f._raw;
    return result;
}

Fixed Fixed::operator++(void) {
    this->_raw++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp = *this;
    this->_raw++;
    return tmp;
}

Fixed Fixed::operator--(void) {
    this->_raw--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp = *this;
    this->_raw--;
    return tmp;
}

int Fixed::getRawBits(void) const { return this->_raw; }

void Fixed::setRawBits(int raw) { this->_raw = raw; }

float Fixed::toFloat(void) const { return (float)this->_raw / (1 << scale); }

int Fixed::toInt(void) const { return this->_raw >> scale; }

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2) {
    return (f1._raw > f2._raw) ? f1 : f2;
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2) {
    return (f1._raw < f2._raw) ? f1 : f2;
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2) {
    return (f1._raw > f2._raw) ? f1 : f2;
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2) {
    return (f1._raw < f2._raw) ? f1 : f2;
}

std::ostream& operator<<(std::ostream& out, const Fixed& f) {
    out << f.toFloat();
    return out;
}