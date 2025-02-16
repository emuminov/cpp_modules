/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:39:13 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/10 21:51:59 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H
#include <iostream>

class Fixed {
  public:
    Fixed(void);
    Fixed(const int raw);
    Fixed(const float raw);
    Fixed(const Fixed& f);
    Fixed& operator=(const Fixed& f);
    bool operator>(const Fixed& f) const;
    bool operator<(const Fixed& f) const;
    bool operator>=(const Fixed& f) const;
    bool operator<=(const Fixed& f) const;
    bool operator==(const Fixed& f) const;
    bool operator!=(const Fixed& f) const;
    Fixed operator+(const Fixed& f) const;
    Fixed operator-(const Fixed& f) const;
    Fixed operator*(const Fixed& f) const;
    Fixed operator/(const Fixed& f) const;
    Fixed operator++(void);
    Fixed operator++(int);
    Fixed operator--(void);
    Fixed operator--(int);
    ~Fixed(void);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    static const Fixed& max(const Fixed& f1, const Fixed& f2);
    static const Fixed& min(const Fixed& f1, const Fixed& f2);
    static Fixed& max(Fixed& f1, Fixed& f2);
    static Fixed& min(Fixed& f1, Fixed& f2);

  private:
    int _raw;
    static const int scale = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& f);
#endif
