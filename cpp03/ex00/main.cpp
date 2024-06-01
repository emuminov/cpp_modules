/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:30:16 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/01 22:18:56 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void) {
	ClapTrap ct1("George");
	ClapTrap ct2(ct1);
	ClapTrap ct3 = ct1;
	std::string target = "training dummy";
	ct1.attack(target);
	ct1.attack(target);
	ct1.attack(target);
	ct1.attack(target);
	ct1.takeDamage(8);
	ct1.beRepaired(3);
	ct1.beRepaired(15);
	ct1.attack(target);
	ct1.attack(target);
	ct1.attack(target);
	ct1.attack(target);
	ct1.attack(target);
	ct1.attack(target);
	ct1.takeDamage(17);
	ct1.attack(target);
	return 0;
}
