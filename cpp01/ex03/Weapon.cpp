/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */ /*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:04:38 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/18 17:12:10 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) { return; }

Weapon::~Weapon() { return; }

const std::string& Weapon::getType() { return this->type; }

void Weapon::setType(std::string type) { this->type = type; }
