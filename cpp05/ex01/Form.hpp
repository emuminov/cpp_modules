#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"
#include <string>
class Form {
  public:
    Form(std::string name, int signing_grade, int executing_grade);
    Form(const Form& f);
    Form& operator=(const Form& f);
    ~Form();

    void beSigned(const Bureaucrat& b);
    const std::string& get_name() const;
    bool get_is_signed() const;
    int get_signing_grade() const;
    int get_executing_grade() const;

    class GradeTooHighException : public std::exception {
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        virtual const char* what() const throw();
    };

  private:
    const std::string m_name;
    const int m_signing_grade;
    const int m_executing_grade;
    bool m_is_signed;
    static void check_grade(int grade);
};
std::ostream& operator<<(std::ostream& o, const Form& f);
#endif
