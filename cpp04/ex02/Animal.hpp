/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:27:31 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/10 19:04:27 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
  public:
    Animal();
    Animal(const Animal& a);
    Animal& operator=(const Animal& a);
    virtual ~Animal();
    virtual void makeSound() const = 0;
    const std::string& getType() const;

  protected:
    Animal(std::string type);
    std::string m_type;
};

#endif
