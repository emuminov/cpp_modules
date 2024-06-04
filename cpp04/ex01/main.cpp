/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:55:28 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/04 15:00:46 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

void base_test() {
	std::cout << "================\n";
	std::cout << "Subject Test Start\n";
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal k = *j;
	const Animal l = *i;

	l.makeSound();
	k.makeSound();

	delete j;
	delete i;
	std::cout << "Subject Test End\n";
	std::cout << "================\n";
}

void subject_test() {
	std::cout << "================\n";
	std::cout << "Subject Test Start\n";
	const Animal* animals[100];
	for (int i = 0; i < 50; i++) {
		animals[i] = new Dog();
	}
	for (int i = 50; i < 100; i++) {
		animals[i] = new Cat();
	}
	for (int i = 0; i < 100; i++) {
		animals[i]->makeSound();
	}
	for (int i = 0; i < 100; i++) {
		delete animals[i];
	}
	std::cout << "Subject Test End\n";
	std::cout << "================\n";
}

void brain_test() {
	std::cout << "================\n";
	std::cout << "Brain Test Start\n";
	const char* base_ideas[3] = {"Meow", "Scratch", "Eat"};
	Cat* cat1 = new Cat();
	for (int i = 0; i < 100; i++) {
		cat1->set_idea(i, base_ideas[i % 3]);
	}
	Cat cat2 = *cat1;
	// for (int i = 0; i < 100; i++) {
	// 	std::cout << cat2.get_idea(i) << " ";
	// }
	// std::cout << "\n";
	// std::cout << cat2.get_idea(-5) << "\n";
	// std::cout << cat2.get_idea(150) << "\n";
	std::cout << "Brain Test End\n";
	std::cout << "================\n";
}

int main (void) {
	base_test();
	subject_test();
	brain_test();
	return 0;
}
