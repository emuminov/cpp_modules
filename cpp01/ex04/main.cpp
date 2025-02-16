/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:52:47 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/20 18:18:13 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <stdlib.h>

std::string* search_and_replace(const std::string& s1, const std::string& s2,
                                std::string* file_contents) {
    size_t pos = file_contents->find(s1);
    while (pos != std::string::npos) {
        file_contents->erase(pos, s1.length());
        file_contents->insert(pos, s2);
        pos = file_contents->find(s1, pos + s2.length());
    };
    return file_contents;
}

std::string* read_file(const std::string& filename) {
    std::ifstream input_file;
    input_file.open(filename.c_str());
    if (!input_file) {
        return (NULL);
    }
    std::string* file_contents = new std::string("");
    std::string file_current_line = "";
    if (input_file.is_open()) {
        while (!input_file.eof()) {
            std::getline(input_file, file_current_line);
            *file_contents += file_current_line;
            if (!input_file.eof())
                *file_contents += '\n';
        }
    }
    input_file.close();
    return file_contents;
}

std::string* write_to_replaced_file(const std::string& filename,
                                    std::string* file_contents) {
    std::string new_filename = filename;
    new_filename += ".replace";
    std::ofstream output_file;
    output_file.open(new_filename.c_str());
    if (!output_file) {
        std::cout << "here";
        return NULL;
    }
    output_file << *file_contents;
    return file_contents;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Correct usage: [filename, s1, s2]" << std::endl;
        return EXIT_FAILURE;
    }

    const std::string filename = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];

    if (s1 == "") {
        std::cerr << "s1 cannot be empty" << std::endl;
        return EXIT_FAILURE;
    }

    std::string* file_contents = read_file(filename);
    if (!file_contents) {
        std::cerr << "Could not reat the file" << std::endl;
        return EXIT_FAILURE;
    }

    search_and_replace(s1, s2, file_contents);
    write_to_replaced_file(filename, file_contents);

    delete file_contents;
    return 0;
}
