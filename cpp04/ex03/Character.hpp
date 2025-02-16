#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>
class Character : public ICharacter
{
  public:
    Character(std::string name);
    ~Character(void);
    Character(Character const& c);
    Character& operator=(Character const& c);
    std::string const& getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
    AMateria* get_materia(int idx);

  private:
    static int const items_capacity = 4;
    std::string m_name;
    AMateria* m_items[items_capacity];
};
#endif
