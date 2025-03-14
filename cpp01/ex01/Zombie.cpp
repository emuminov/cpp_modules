/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:13:33 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/18 16:00:45 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(std::string name) : name(name) { return; }
Zombie::Zombie() : name("") { return; }

Zombie::~Zombie()
{
    std::cout << this->name << '\n';
    return;
}

void Zombie::announce(void) { std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << '\n'; }

std::string Zombie::get_name() { return this->name; }

void Zombie::set_name(std::string name) { this->name = name; }
