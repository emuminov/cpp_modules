/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:27:34 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/03 17:43:28 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <string>

class Cat : public Animal
{
  public:
    Cat();
    Cat(const Cat& a);
    Cat& operator=(const Cat& a);
    ~Cat();
    void makeSound() const;

  protected:
    std::string m_type;
};

#endif
