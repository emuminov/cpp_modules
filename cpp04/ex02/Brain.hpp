/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:36:16 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/04 14:06:50 by emuminov         ###   ########.fr       */
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
    const std::string& get_idea(int index) const;
    void set_idea(int index, std::string idea);

  private:
    std::string m_ideas[100];
};

#endif
