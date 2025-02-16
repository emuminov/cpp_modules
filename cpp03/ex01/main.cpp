/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:30:16 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/01 18:54:47 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main (void) {
	ClapTrap ct("George");
	ScavTrap st("Leonard");
	std::string target = "training dummy";
	st.attack(target);
	st.attack(target);
	st.attack(target);
	st.attack(target);
	st.attack(target);
	st.takeDamage(8);
	st.beRepaired(3);
	st.beRepaired(15);
	st.attack(target);
	st.attack(target);
	st.attack(target);
	st.attack(target);
	st.attack(target);
	st.attack(target);
	st.takeDamage(17);
	st.attack(target);
	return 0;
}
