#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main(void) {
    Bureaucrat b0("Vasya", 146);
    Bureaucrat b1("Bob", 142);
    Bureaucrat b2("Daniel", 42);
    Bureaucrat b3("Chad", 2);

    ShrubberyCreationForm sf("Chad's Home");
    RobotomyRequestForm rf(b1.getName());
    PresidentialPardonForm pf(b3.getName());

    std::cout << "========\n";
    std::cout << sf << "\n";
    b0.signForm(sf);
    b1.signForm(sf);
    b1.executeForm(sf);
    b2.executeForm(sf);

    std::cout << "========\n";
    std::cout << rf << "\n";
    b2.executeForm(rf);
    b2.signForm(rf);
    b3.executeForm(rf);
    b3.signForm(rf);
    b3.executeForm(rf);
    b3.increaseGrade();
    b3.executeForm(rf);

    std::cout << "========\n";
    std::cout << pf << "\n";
    b2.executeForm(pf);
    b3.executeForm(pf);
    b2.signForm(pf);
    b2.executeForm(pf);
    b3.signForm(pf);
    b3.executeForm(pf);
    return 0;
}
