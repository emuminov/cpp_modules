/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:36:03 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/18 15:39:35 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main (void) {
	randomChump("Stan");
	randomChump("Laura");
	Zombie* z = newZombie("Gregory");
	z->announce();
	delete z;
	return 0;
}
