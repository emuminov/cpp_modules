/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:39:11 by emuminov          #+#    #+#             */
/*   Updated: 2024/07/19 19:15:40 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed(void) : _raw(0) { return; }

Fixed::Fixed(const int nbr) : _raw(nbr << _scale) { return; }

Fixed::Fixed(const float nbr) : _raw(roundf(nbr * (1 << _scale))) { return; }

Fixed::~Fixed(void) { return; }

Fixed::Fixed(const Fixed& f) : _raw(f._raw) {
    return;
}

Fixed& Fixed::operator=(const Fixed& f) {
	if (this != &f)
		_raw = f._raw;
    return (*this);
}

bool Fixed::operator>(const Fixed& f) const { return _raw > f._raw; }

bool Fixed::operator<(const Fixed& f) const { return _raw < f._raw; }

bool Fixed::operator>=(const Fixed& f) const { return _raw >= f._raw; }

bool Fixed::operator<=(const Fixed& f) const { return _raw <= f._raw; }

bool Fixed::operator==(const Fixed& f) const { return _raw == f._raw; }

bool Fixed::operator!=(const Fixed& f) const { return _raw != f._raw; }

Fixed Fixed::operator+(const Fixed& f) const {
	Fixed result(0);
	result._raw = _raw + f._raw;
    return result;
}

Fixed Fixed::operator-(const Fixed& f) const {
	Fixed result(0);
	result._raw = _raw - f._raw;
    return result;
}

Fixed Fixed::operator*(const Fixed& f) const {
	Fixed res(0);
	res._raw = (_raw * f._raw) >> _scale;
    return res;
}

Fixed Fixed::operator/(const Fixed& f) const {
	Fixed res(0);
	res._raw = _raw * (1 << _scale) / f._raw;
    return res;
}

Fixed Fixed::operator++(void) {
    _raw++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp = *this;
    _raw++;
    return tmp;
}

Fixed Fixed::operator--(void) {
    _raw--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp = *this;
    _raw--;
    return tmp;
}

int Fixed::getRawBits(void) const { return _raw; }

void Fixed::setRawBits(int raw) { _raw = raw; }

float Fixed::toFloat(void) const { return (float)_raw / (1 << _scale); }

int Fixed::toInt(void) const { return _raw >> _scale; }

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
