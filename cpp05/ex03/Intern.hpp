#ifndef INTERN_HPP
#define INTERN_HPP
#include <exception>
#include <string>
class AForm;
class Intern
{
  public:
    Intern();
    Intern(const Intern& i);
    Intern& operator=(const Intern& i);
    ~Intern();

    AForm* makeForm(const std::string& target_form_name, const std::string& target) const;

    class InvalidFormNameException : public std::exception
    {
        virtual const char* what() const throw();
    };

    typedef struct s_form_creator
    {
        const char* name;
        AForm* (Intern::*create_form)(const std::string&) const;
    } t_form_creator;

  private:
    AForm* make_robotomy_request_form(const std::string& target) const;
    AForm* make_presidential_pardon_form(const std::string& target) const;
    AForm* make_shrubbery_creation_form(const std::string& target) const;
};
#endif
