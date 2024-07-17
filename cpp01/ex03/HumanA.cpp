/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:09:52 by emuminov          #+#    #+#             */
/*   Updated: 2024/07/17 16:15:14 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& w) : name(name), weapon(w) {
    return;
}

HumanA::~HumanA() { return; }

void HumanA::attack() const {
    std::cout << name << " attacks with their " << weapon.getType()
              << '\n';
}
