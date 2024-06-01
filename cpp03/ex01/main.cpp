/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:30:16 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/01 22:24:59 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main (void) {
	ScavTrap st1("Leonard");
	ScavTrap st2(st1);
	ScavTrap st3 = st1;
	std::string target = "training dummy";
	st1.attack(target);
	st1.attack(target);
	st1.attack(target);
	st1.attack(target);
	st1.attack(target);
	st1.takeDamage(8);
	st1.beRepaired(3);
	st1.beRepaired(15);
	st1.attack(target);
	st1.attack(target);
	st1.attack(target);
	st1.attack(target);
	st1.attack(target);
	st1.attack(target);
	st1.takeDamage(17);
	st1.attack(target);
	return 0;
}
