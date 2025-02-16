/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:29:13 by emuminov          #+#    #+#             */
/*   Updated: 2024/07/22 19:16:22 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap(std::string name)
    : m_name(name), m_hit_points(default_hit_points),
      m_energy_points(default_energy_points),
      m_attack_damage(default_attack_damage) {
    std::cout << "A wild ClapTrap appears!\n";
    return;
}

ClapTrap::ClapTrap(std::string name, int hit_points, int energy_points, int attack_damage) : m_name(name), m_hit_points(hit_points), m_energy_points(energy_points), m_attack_damage(attack_damage) {
    std::cout << "A wild ClapTrap appears!\n";
    return;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap suddenly disappears...\n";
    return;
}

ClapTrap::ClapTrap(const ClapTrap& ct) : m_name(ct.m_name) {
    std::cout << "ClapTrap " << m_name << " clones itself!\n";
    return;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ct) {
    m_name = ct.m_name;
    std::cout << "ClapTrap " << m_name << " clones itself!\n";
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (m_hit_points <= 0) {
        std::cout << "ClapTrap is dead!..\n";
        return;
    } else if (m_energy_points <= 0) {
        std::cout << "Not enough energy...\n";
        return;
    }
    m_energy_points--;
    std::cout << "ClapTrap " << m_name << " attacks " << target << ", causing "
              << m_attack_damage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (m_hit_points <= 0) {
        std::cout << "ClapTrap is already dead. Stop.\n";
        return;
    }
    std::cout << "ClapTrap " << m_name << " was attacked, and now lost "
              << amount << " hit points!\n";
    m_hit_points -= amount;
    if (m_hit_points <= 0) {
        std::cout << "ClapTrap " << m_name << " is down!\n";
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (m_hit_points <= 0) {
        std::cout << "ClapTrap is already dead. Stop.\n";
        return;
    } else if (m_energy_points <= 0) {
        std::cout << "Not enough energy...\n";
        return;
    }
    std::cout << "Hit points: " << m_hit_points << "\n";
    std::cout << "Amount: " << amount << "\n";
    m_energy_points--;
    std::cout << "ClapTrap " << m_name << " was repaired, and now gained "
              << amount << " hit points!\n";
    m_hit_points += amount;
}
