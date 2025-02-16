#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(std::string const& type) : m_type(type) { return; }

AMateria::~AMateria(void) { return; }

AMateria::AMateria(AMateria const& m) : m_type(m.m_type) { return; }

AMateria& AMateria::operator=(AMateria const& m) {
	if (this != &m)
		m_type = m.m_type;
	return *this;
}

std::string const& AMateria::getType() const { return m_type; }


void AMateria::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wound *\n";
}
