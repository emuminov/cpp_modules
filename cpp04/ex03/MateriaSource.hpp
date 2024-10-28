#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <string>
class MateriaSource : public IMateriaSource
{
  public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(MateriaSource const& ms);
    MateriaSource& operator=(MateriaSource const& ms);
    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const& type);

  private:
    static int const materias_capacity = 4;
    AMateria* m_learned_materias[4];
};
#endif
