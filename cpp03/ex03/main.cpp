/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:30:16 by emuminov          #+#    #+#             */
/*   Updated: 2024/07/23 18:21:43 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) {
    DiamondTrap dt1("Leonard");
    DiamondTrap dt2(dt1);
    DiamondTrap dt3("Don");
	dt3 = dt1;
    std::string target = "training dummy";
    dt3.attack(target);
    // dt3.attack(target);
    // dt3.attack(target);
    // dt3.attack(target);
    // dt3.attack(target);
    // dt3.takeDamage(8);
    // dt3.beRepaired(3);
    // dt3.beRepaired(15);
    // dt3.attack(target);
    // dt3.attack(target);
    // dt3.attack(target);
    // dt3.attack(target);
    // dt3.attack(target);
    // dt3.attack(target);
    // dt3.takeDamage(17);
    // dt3.attack(target);
    dt1.whoAmI();
    dt2.whoAmI();
    dt3.whoAmI();
    return 0;
}
