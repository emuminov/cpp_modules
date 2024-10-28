#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

Ice::Ice(void) : AMateria("ice") { return; }

Ice::~Ice(void) { return; }

Ice::Ice(Ice const& i) : AMateria(i) { return; }

Ice& Ice::operator=(Ice const& c)
{
    if (this != &c)
        m_type = c.m_type;
    return *this;
}

AMateria* Ice::clone() const { return new Ice(); }

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
