/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:38:04 by emuminov          #+#    #+#             */
/*   Updated: 2024/07/23 18:54:45 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap(std::string name)
    : ClapTrap(name, default_hit_points, default_energy_points,
               default_attack_damage) {
    std::cout << "A wild ScavTrap appears!\n";
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap suddenly disappears...\n";
    return;
}

ScavTrap::ScavTrap(const ScavTrap& st)
    : ClapTrap(st.m_name, default_hit_points, default_energy_points,
               default_attack_damage) {
    std::cout << "ScavTrap " << m_name << " clones itself!\n";
    return;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& st) {
    m_name = st.m_name;
    std::cout << "ScavTrap " << m_name << " clones itself!\n";
    return *this;
}

void ScavTrap::guardGate(void) {
    if (m_hit_points <= 0) {
        std::cout << "ScavTrap is dead!..\n";
        return;
    } else if (m_energy_points <= 0) {
        std::cout << "Not enough energy...\n";
        return;
    }
    m_energy_points--;
    std::cout << "ScavTrap " << m_name << " is now in a guard keeper mode!";
}

void ScavTrap::attack(const std::string& target) {
    if (m_hit_points <= 0) {
        std::cout << "ScavTrap is dead!..\n";
        return;
    } else if (m_energy_points <= 0) {
        std::cout << "Not enough energy...\n";
        return;
    }
    m_energy_points--;
    std::cout << "ScavTrap " << m_name << " attacks " << target << ", causing "
              << m_attack_damage << " points of damage!\n";
}
