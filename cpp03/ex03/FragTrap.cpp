/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:38:04 by emuminov          #+#    #+#             */
/*   Updated: 2024/07/23 18:56:03 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap(std::string name) : ClapTrap(name, default_hit_points, default_energy_points, default_attack_damage) {
    std::cout << "A wild FragTrap appears!\n";
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap suddenly disappears...\n";
    return;
}

FragTrap::FragTrap(const FragTrap& ft) : ClapTrap(ft.m_name, default_hit_points, default_energy_points, default_attack_damage) {
    std::cout << "FragTrap " << m_name << " clones itself!\n";
    return;
}

FragTrap& FragTrap::operator=(const FragTrap& ft) {
    m_name = ft.m_name;
    std::cout << "FragTrap " << m_name << " clones itself!\n";
    return *this;
}

void FragTrap::highFiveGuys() {
	if (m_hit_points <= 0) {
        std::cout << "FragTrap is dead!..\n";
        return;
    } else if (m_energy_points <= 0) {
        std::cout << "Not enough energy...\n";
        return;
    }
    m_energy_points--;
    std::cout << "FragTrap " << m_name << " gives high five!\n";
}

void FragTrap::attack(const std::string& target) {
    if (m_hit_points <= 0) {
        std::cout << "FragTrap is dead!..\n";
        return;
    } else if (m_energy_points <= 0) {
        std::cout << "Not enough energy...\n";
        return;
    }
    m_energy_points--;
    std::cout << "FragTrap " << m_name << " attacks " << target << ", causing "
              << m_attack_damage << " points of damage!\n";
}
