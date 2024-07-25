/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:27:34 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/03 19:00:20 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal {
  public:
    Cat();
    Cat(const Cat& a);
    Cat& operator=(const Cat& a);
    ~Cat();
    void makeSound() const;
    const std::string& get_idea(int index) const;
    void set_idea(int index, std::string idea);

  protected:
    std::string m_type;

  private:
    Brain* m_brain;
};

#endif
