/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:27:38 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/03 16:18:27 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* w_i = new WrongCat();
    const WrongAnimal* w_meta = new WrongAnimal();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << w_i->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    w_i->makeSound();
    w_meta->makeSound();

    delete meta;
    delete j;
    delete i;
    delete w_i;
    delete w_meta;
    return 0;
}
