#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void) {
    {
        Bureaucrat b("Chad", 2);
        Intern i;

        AForm* f = i.makeForm("shrubbery creation", "Chad's Home");

        b.signForm(*f);
        b.executeForm(*f);

        delete f;
    }
    {
        Bureaucrat b("Chad", 2);
        Intern i;

        try {
            AForm* f = i.makeForm("some nonsense", "Chad's Home");

            b.signForm(*f);
            b.executeForm(*f);
            delete f;
        } catch (std::exception& e) {
            std::cerr << e.what() << "\n";
        }
    }

    return 0;
}
