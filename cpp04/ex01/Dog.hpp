/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:27:37 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/04 12:16:31 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal
{
  public:
    Dog();
    Dog(const Dog& a);
    Dog& operator=(const Dog& a);
    ~Dog();
    void makeSound() const;
    const std::string& get_idea(int index) const;
    void set_idea(int index, std::string idea);

  protected:
    std::string m_type;

  private:
    Brain* m_brain;
};

#endif
