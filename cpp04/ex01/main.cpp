/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:55:28 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/03 19:30:16 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main (void) {
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal* k = j;
	const Animal* l = i;

	l->makeSound();
	k->makeSound();

	delete j;
	delete i;
	return 0;
}
