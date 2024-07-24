#include "Cure.hpp"
#include "ICharacter.hpp"
#include <string>
#include <iostream>

Cure::Cure(void) : AMateria("cure") { return; }

Cure::~Cure(void) { return; }

Cure::Cure(Cure const& c) : AMateria(c) { return; }

Cure& Cure::operator=(Cure const& c) {
	if (this != &c)
		m_type = c.m_type;
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wound *\n";
}
