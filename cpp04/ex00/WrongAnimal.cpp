/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:55:46 by emuminov          #+#    #+#             */
/*   Updated: 2024/07/24 14:07:17 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal() : m_type("WrongAnimal")
{
    std::cout << "WrongAnimal constructor is called\n";
    return;
}

WrongAnimal::WrongAnimal(std::string type) : m_type(type)
{
    std::cout << "Protected WrongAnimal constructor is called\n";
    return;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor is called\n";
    return;
}

WrongAnimal::WrongAnimal(const WrongAnimal& a) : m_type(a.m_type)
{
    std::cout << "WrongAnimal copy constructor is called\n";
    return;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& a)
{
    std::cout << "WrongAnimal copy assign operator is called\n";
    if (this != &a)
        m_type = a.m_type;
    return *this;
}

const std::string& WrongAnimal::getType() const { return m_type; }

void WrongAnimal::makeSound() const { std::cout << "<dead silence>\n"; }
