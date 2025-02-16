#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential pardon form", signing_grade, executing_grade),
      m_target(target) {
    return;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& scf)
    : AForm(scf), m_target(scf.m_target) {
    return;
}

PresidentialPardonForm&
PresidentialPardonForm::operator=(const PresidentialPardonForm& scf) {
    if (&scf == this)
        return *this;
    this->m_target = scf.m_target;
    return *this;
}

void PresidentialPardonForm::do_execution() const {
    std::cout << m_target << " has been pardoned by Zaphod Beeblebrox!\n";
    return;
}

PresidentialPardonForm::~PresidentialPardonForm() { return; }
