#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void) {
    Form f1("billing form", 1, 10);
    Bureaucrat b1("Daniel", 1);
    std::cout << f1 << '\n';
    b1.signForm(f1);
    std::cout << f1 << '\n';

    std::cout << "===\n";

    Form f2("billing form", 1, 10);
    Bureaucrat b2("Bob", 5);
    std::cout << f2 << '\n';
    b2.signForm(f2);
    std::cout << f2 << '\n';

    std::cout << "===\n";

    // will throw
    try {
        Form f3("billing form", 0, 10);
        std::cout << f3 << '\n';
        b1.signForm(f3);
        std::cout << f3 << '\n';
    } catch (std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    std::cout << "===\n";

    // will throw
    try {
        Form f3("billing form", 1, 151);
        std::cout << f3 << '\n';
        b1.signForm(f3);
        std::cout << f3 << '\n';
    } catch (std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
