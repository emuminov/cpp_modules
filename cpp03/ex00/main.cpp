/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:30:16 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/31 16:33:00 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void) {
	ClapTrap ct("George");
	std::string target = "training dummy";
	ct.attack(target);
	ct.attack(target);
	ct.attack(target);
	ct.attack(target);
	ct.takeDamage(8);
	ct.beRepaired(3);
	ct.beRepaired(15);
	ct.attack(target);
	ct.attack(target);
	ct.attack(target);
	ct.attack(target);
	ct.attack(target);
	ct.attack(target);
	ct.takeDamage(17);
	ct.attack(target);
	return 0;
}
