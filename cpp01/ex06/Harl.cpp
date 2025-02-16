/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:19:15 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/21 16:20:16 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl() { return; }

Harl::~Harl() { return; }

void Harl::complain(std::string level) {
	switch (level[0]) {
		case 'D':
			this->debug();
		case 'I':
			this->info();
		case 'W':
			this->warning();
		case 'E':
			this->error();
			break;
		default:
			std::cerr << "[complain complain]\n";
			return;
	}
}

void Harl::debug(void) {
	std::cout << "[DEBUG]\n";
    std::cout << "I love having extra bacon for my "
                 "7XL-double-cheese-triple-pickle-special-ketchup burger. I "
                 "really do!"
              << std::endl;
}

void Harl::info(void) {
	std::cout << "[INFO]\n";
    std::cout << "I cannot believe adding extra bacon costs more money. You "
                 "didn’t put enough bacon in my burger! If you did, I wouldn’t "
                 "be asking for more!"
              << std::endl;
}

void Harl::warning(void) {
	std::cout << "[WARNING]\n";
    std::cout
        << "I think I deserve to have some extra bacon for free. I’ve "
           "been coming for years whereas you started working here since last "
           "month."
        << std::endl;
}

void Harl::error(void) {
	std::cout << "[ERROR]\n";
    std::cout << "This is unacceptable! I want to speak to the manager now."
              << std::endl;
}
