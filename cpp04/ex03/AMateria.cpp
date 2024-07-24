#include "AMateria.hpp"

AMateria::AMateria(std::string const& type) : m_type(type) { return; }

AMateria::~AMateria(void) { return; }

AMateria::AMateria(AMateria const& m) : m_type(m.m_type) { return; }

AMateria& AMateria::operator=(AMateria const& m) {
	if (this != &m)
		m_type = m.m_type;
	return *this;
}

std::string const& AMateria::getType() const { return m_type; }
