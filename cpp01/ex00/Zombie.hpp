/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:12:23 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/18 15:24:25 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <string>

class Zombie {
public:
	Zombie(std::string name);
	~Zombie();
	void announce(void);

private:
	std::string name;
};
#endif
