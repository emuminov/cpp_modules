#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
class ShrubberyCreationForm : public AForm
{
  public:
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& scf);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& scf);
    ~ShrubberyCreationForm();

  private:
    std::string m_target;
    static const int signing_grade = 145;
    static const int executing_grade = 137;
    void do_execution() const;
};
#endif
