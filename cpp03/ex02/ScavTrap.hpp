/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:37:46 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/01 22:36:11 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap {
public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &st);
	ScavTrap &operator=(const ScavTrap &st);
	~ScavTrap();

	void		guardGate(void);
	void		attack(const std::string& target);

private:
	static const int default_hit_points = 100;
	static const int default_energy_points = 50;
	static const int default_attack_damage = 20;
};

#endif
