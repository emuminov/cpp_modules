/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:36:16 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/03 18:04:43 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
  public:
    Brain();
    Brain(const Brain& a);
    Brain& operator=(const Brain& a);
    ~Brain();
	std::string ideas[100];
};

#endif
