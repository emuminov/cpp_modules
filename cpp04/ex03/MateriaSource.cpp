#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() : m_learned_materias() { return; }

MateriaSource::~MateriaSource() {
	for (int i = 0; i < materias_capacity; i++) {
		delete m_learned_materias[i];
	}
}

MateriaSource::MateriaSource(MateriaSource const& ms) : m_learned_materias() {
	for (int i = 0; i < materias_capacity; i++) {
		if (ms.m_learned_materias[i])
			m_learned_materias[i] = ms.m_learned_materias[i]->clone();
		else
			m_learned_materias[i] = nullptr;
	}
}

MateriaSource& MateriaSource::operator=(MateriaSource const& ms) {
	if (this != &ms) {
		for (int i = 0; i < materias_capacity; i++) {
			if (ms.m_learned_materias[i])
				m_learned_materias[i] = ms.m_learned_materias[i]->clone();
			else
				m_learned_materias[i] = nullptr;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < materias_capacity; i++) {
		if (!m_learned_materias[i])
			m_learned_materias[i] = m;
	}
}


AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < materias_capacity; i++) {
		if (m_learned_materias[i] && m_learned_materias[i]->getType() == type)
			return m_learned_materias[i]->clone();
	}
	return nullptr;
}
