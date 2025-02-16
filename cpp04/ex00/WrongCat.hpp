/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:55:42 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/03 16:12:32 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal {
  public:
    WrongCat();
    WrongCat(const WrongCat& a);
    WrongCat& operator=(const WrongCat& a);
    ~WrongCat();
    void makeSound() const;

  protected:
    std::string m_type;
};

#endif
