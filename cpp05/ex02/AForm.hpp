#ifndef AFORM_HPP
#define AFORM_HPP
#include "Bureaucrat.hpp"
#include <string>
class AForm {
  public:
    AForm(std::string name, int signing_grade, int executing_grade);
    AForm(const AForm& f);
    AForm& operator=(const AForm& f);
    virtual ~AForm();

    void beSigned(const Bureaucrat& b);
    void execute(const Bureaucrat& executor) const;
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

    class NotSignedException : public std::exception {
        virtual const char* what() const throw();
    };

  private:
    const std::string m_name;
    const int m_signing_grade;
    const int m_executing_grade;
    bool m_is_signed;
    static void check_grade(int grade);
    virtual void do_execution() const = 0;
};
std::ostream& operator<<(std::ostream& o, const AForm& f);
#endif
