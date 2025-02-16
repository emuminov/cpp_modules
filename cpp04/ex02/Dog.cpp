/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:27:36 by emuminov          #+#    #+#             */
/*   Updated: 2024/07/24 14:08:51 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog"), m_brain(new Brain)
{
    std::cout << "Dog constructor is called\n";
    return;
}

Dog::~Dog()
{
    std::cout << "Dog destructor is called\n";
    delete m_brain;
    return;
}

Dog::Dog(const Dog& a) : m_type(a.m_type), m_brain(new Brain(*a.m_brain))
{
    std::cout << "Dog copy constructor is called\n";
    return;
}

Dog& Dog::operator=(const Dog& a)
{
    std::cout << "Dog copy assign operator is called\n";
    if (this != &a)
    {
        m_type = a.m_type;
        *m_brain = *a.m_brain;
    }
    return *this;
}

void Dog::makeSound() const { std::cout << "BARK BARK BARK!!!\n"; }

const std::string& Dog::get_idea(int index) const { return m_brain->get_idea(index); }

void Dog::set_idea(int index, std::string idea) { m_brain->set_idea(index, idea); }
