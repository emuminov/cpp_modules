#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery creation form", signing_grade, executing_grade), m_target(target)
{
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& scf)
    : AForm(scf), m_target(scf.m_target)
{
    return;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& scf)
{
    if (&scf == this)
        return *this;
    this->m_target = scf.m_target;
    return *this;
}

void ShrubberyCreationForm::do_execution() const
{
    const std::string file_name = m_target + "_shrubbery";
    std::ofstream output_file(file_name.c_str());
    if (!output_file.is_open())
        return;
    output_file << "⠀⠀⠀⠀⢀⣀⠄⠠⠐⠐⠈⠀⠁⠒⠋⠁⠁⠁⠁⠁⠈⠈⠈⠀⢁⣁⡩⠇⠀⠀⠀⠀⠀⠀⠀⠀\n"
                   "⠀⠀⢀⣀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠁⠁⠂⠄⡀⡀⠀⠀⠀⠀⠀⠀\n"
                   "⢐⠋⠁⠀⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠑⢤⠀⠀⠀\n"
                   "⠸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠒⠚⠄⡀⠀\n"
                   "⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢣\n"
                   "⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸\n"
                   "⠀⠈⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠤⣤⠤⠼\n"
                   "⢰⠊⠁⠀⠀⠀⠀⠀⡠⡻⣁⣁⣀⣀⠤⠤⠤⠒⠒⠒⠒⠒⠒⠒⠒⠒⢲⢀⠀⠀⠀⠀⠀⠀⠃⡀\n"
                   "⠀⣇⠀⠀⢀⡀⡤⠊⠀⠇⠀⠀⠀⠀⢀⣤⡄⠀⠀⠀⠀⣤⡄⠀⠀⠀⢸⠀⠣⡀⠀⠀⠀⠀⠀⠡\n"
                   "⠀⠈⠉⠉⠁⠀⠀⠀⢠⠁⠀⠀⠀⢠⢻⡿⡟⠀⠀⠀⢸⣿⣿⠀⠀⠀⢸⠀⠀⠣⠄⠤⠤⠄⠂⠚\n"
                   "⠀⠀⠀⠀⠀⠀⠀⠀⡸⠀⠀⠀⠀⠈⠉⠉⢁⢠⠀⠀⠑⠚⠋⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                   "⠀⠀⠀⠀⠀⠀⠀⢀⠆⠀⠀⠀⠀⠀⠀⠀⠀⠙⠷⠦⠤⠶⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                   "⠀⠀⠀⠀⠀⠀⠀⠘⠒⠂⠒⠒⠂⠒⠤⠤⠤⢄⣀⣀⡀⠀⠀⠀⠀⠀⠘⡄⠀⠀⠀⠀⠀⠀⠀⠀\n"
                   "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠒⠒⠲⠤⠇⠀⠀⠀⠀⠀⠀⠀⠀\n";
    output_file.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() { return; }
