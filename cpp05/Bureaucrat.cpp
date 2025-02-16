#include "Bureaucrat.hpp"
#include <string>

Bureaucrat::Bureaucrat(std::string name, int grade) : m_name(name),
	m_grade(grade) { return; }

Bureaucrat::Bureaucrat(const Bureaucrat &b) : m_name(b.m_name),
	m_grade(b.m_grade) { return; }

Bureaucrat Bureaucrat::operator=(const Bureaucrat &b) {
	if (&b == this)
		return *this;
	m_grade = b.m_grade;
	return *this;
}

Bureaucrat::~Bureaucrat() { return; }

int Bureaucrat::getGrade() const { return m_grade; }

const std::string& Bureaucrat::getName() const { return m_name; };

// TODO: exception logic
void Bureaucrat::increaseGrade() {
	m_grade--;
}

// TODO: exception logic
void Bureaucrat::dereaseGrade() {
	m_grade++;
}

std::ostream operator<<(std::ostream &o, const Bureaucrat &b);
