#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <string>
class ICharacter;
class AMateria
{
  public:
    AMateria(std::string const& type);
    AMateria(AMateria const& type);
    virtual ~AMateria(void);
    AMateria& operator=(AMateria const& m);
    std::string const& getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);

  protected:
    std::string m_type;
};
#endif
