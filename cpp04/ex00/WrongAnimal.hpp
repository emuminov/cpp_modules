/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:55:45 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/03 15:58:05 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal
{
  public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& a);
    WrongAnimal& operator=(const WrongAnimal& a);
    ~WrongAnimal();
    void makeSound() const;
    const std::string& getType() const;

  protected:
    WrongAnimal(std::string type);
    std::string m_type;
};

#endif
