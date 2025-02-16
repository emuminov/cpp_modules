#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"
#include <string>
class Ice : public AMateria
{
  public:
    Ice(void);
    ~Ice(void);
    Ice(Ice const& c);
    Ice& operator=(Ice const& c);
    std::string const& getType() const;
    AMateria* clone() const;
    void use(ICharacter& target);
};
#endif
