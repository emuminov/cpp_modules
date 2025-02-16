/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:39:18 by emuminov          #+#    #+#             */
/*   Updated: 2024/07/18 18:53:16 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    Fixed const c(Fixed(10.10f) / Fixed(2));
    Fixed const d(Fixed(10.10f) + Fixed(2));
    Fixed const f(Fixed(10.10f) - Fixed(2));
    std::cout << a << "\n";
    std::cout << ++a << "\n";
    std::cout << a << "\n";
    std::cout << a++ << "\n";
    std::cout << a << "\n";
    std::cout << b << "\n";
    std::cout << c << "\n";
    std::cout << d << "\n";
    std::cout << f << "\n";
    std::cout << (a <= b) << "\n";
    std::cout << (c >= d) << "\n";
    std::cout << (f > d) << "\n";
    std::cout << (f < c) << "\n";
    std::cout << Fixed::max(a, b) << "\n";
    return 0;
}
