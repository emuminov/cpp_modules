/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:04:15 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/18 17:27:00 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H
#include <string>

class Weapon {
public:
	Weapon(std::string type);
	~Weapon();
	const std::string& getType();
	void setType(std::string type);
private:
	std::string type;
};
#endif
