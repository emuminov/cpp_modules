/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:25:43 by emuminov          #+#    #+#             */
/*   Updated: 2024/07/17 16:14:59 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string name) : name(name), weapon(NULL) { return; }

HumanB::~HumanB() { return; }

void HumanB::attack() const {
    if (weapon) {
        std::cout << name << " attacks with their "
                  << weapon->getType() << '\n';
    } else {
        std::cout << name << " attacks with their "
                  << "fist" << '\n';
    }
}

void HumanB::setWeapon(Weapon& w) { weapon = &w; }
