/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:52:47 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/18 18:51:06 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	if (argc != 4) {
		std::cerr << "Correct usage: [filename, s1, s2]" << std::endl;
		return EXIT_FAILURE;
	}

	const char* filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream file;
	file.open(filename);
	if (!file) {
		std::cerr << "Cannot access file" << std::endl;
		return EXIT_FAILURE;
	}
	std::string file_contents = "";
	std::string file_current_word = "";
	if (file.is_open()) {
		while (file >> file_current_word) {
			file_contents += file_current_word;
		}
	}
	std::cout << file_contents << std::endl;
	file.close();
	return 0;
}
