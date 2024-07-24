/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:30:16 by emuminov          #+#    #+#             */
/*   Updated: 2024/07/23 18:48:50 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    ClapTrap ct1("George");
    ClapTrap ct2(ct1);
    ClapTrap ct3("Don");
    ct3 = ct1;
    std::string target = "training dummy";
    ct3.attack(target);
    ct3.attack(target);
    ct3.attack(target);
    ct3.attack(target);
    ct3.takeDamage(8);
    ct3.beRepaired(3);
    ct3.beRepaired(15);
    ct3.attack(target);
    ct3.attack(target);
    ct3.attack(target);
    ct3.attack(target);
    ct3.attack(target);
    ct3.attack(target);
    ct3.takeDamage(17);
    ct3.attack(target);
    return 0;
}
