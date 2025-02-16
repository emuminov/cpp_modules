#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void subject_test() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
}

// ensures that all copied objects are copied deeply
void copy_test() {
    MateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    MateriaSource* src_clone1 = new MateriaSource(*src);
    MateriaSource* src_clone2 = new MateriaSource();
    src_clone2->learnMateria(new Cure());
    src_clone2->learnMateria(new Ice());
    *src_clone2 = *src_clone1;
    Character* me = new Character("me");
    AMateria* tmp;
    tmp = src_clone2->createMateria("ice");
    me->equip(tmp);
    tmp = src_clone2->createMateria("ice");
    me->equip(tmp);
    Character* my_clone1 = new Character(*me);
    Character my_clone2 = Character("another me");
    tmp = src_clone2->createMateria("cure");
    my_clone2.equip(tmp);
    tmp = src_clone2->createMateria("cure");
    my_clone2.equip(tmp);
    my_clone2 = *my_clone1;
    ICharacter* bob = new Character("bob");
    my_clone1->use(0, *bob);
    my_clone1->use(1, *bob);
    my_clone2.use(0, *bob);
    my_clone2.use(1, *bob);

    delete bob;
    delete me;
    delete my_clone1;
    delete src;
    delete src_clone1;
    delete src_clone2;
}

int main() {
    subject_test();
    copy_test();
    return 0;
}
