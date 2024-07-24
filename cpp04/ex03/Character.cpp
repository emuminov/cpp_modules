#include "Character.hpp"
#include <string>

Character::Character(std::string name) : m_name(name), m_items() { return; }

Character::~Character(void) {
	for (int i = 0; i < items_capacity; i++) {
		delete m_items[i];
	}
}

Character::Character(Character const& c) : m_name(c.m_name), m_items() {
	for (int i = 0; i < items_capacity; i++) {
		if (c.m_items[i])
			m_items[i] = c.m_items[i]->clone();
		else
			m_items[i] = nullptr;
	}
	return;
}

Character& Character::operator=(Character const& c) {
	if (this != &c) {
		m_name = c.m_name;
		for (int i = 0; i < items_capacity; i++) {
			if (c.m_items[i])
				m_items[i] = c.m_items[i]->clone();
			else
				m_items[i] = nullptr;
		}
	}
	return *this;
}

std::string const& Character::getName() const { return m_name; }

void Character::equip(AMateria* m) {
	for (int i = 0; i < items_capacity; i++) {
		if (!m_items[i])
			m_items[i] = m;
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > (items_capacity - 1))
		return;
	m_items[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > (items_capacity - 1) || !m_items[idx])
		return;
	m_items[idx]->use(target);
}

AMateria* Character::get_materia(int idx) {
	if (idx < 0 || idx > (items_capacity - 1))
		return nullptr;
	return m_items[idx];
}
