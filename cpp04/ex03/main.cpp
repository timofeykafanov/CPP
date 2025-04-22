#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

void testSubjectExample() {
    std::cout << "\n===== SUBJECT EXAMPLE TEST =====\n" << std::endl;
    
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

void testAdditionalFunctionality() {
    std::cout << "\n===== ADDITIONAL FUNCTIONALITY TEST =====\n" << std::endl;
    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    std::cout << "\nTrying to learn a 5th materia:" << std::endl;
    src->learnMateria(new Ice());
    
    std::cout << "\nCreating and testing Alice:" << std::endl;
    Character* alice = new Character("Alice");
    
    AMateria* m1 = src->createMateria("ice");
    alice->equip(m1);
    AMateria* m2 = src->createMateria("cure");
    alice->equip(m2);
    AMateria* m3 = src->createMateria("ice");
    alice->equip(m3);
    AMateria* m4 = src->createMateria("cure");
    alice->equip(m4);
    
    std::cout << "\nTrying to equip a 5th materia:" << std::endl;
    AMateria* m5 = src->createMateria("ice");
    alice->equip(m5);
    
    std::cout << "\nCreating Charlie:" << std::endl;
    ICharacter* charlie = new Character("Charlie");
    
    std::cout << "\nAlice using materias on Charlie:" << std::endl;
    alice->use(0, *charlie);
    alice->use(1, *charlie);
    alice->use(2, *charlie);
    alice->use(3, *charlie);
    
    std::cout << "\nTesting invalid indices:" << std::endl;
    alice->use(-1, *charlie);
    alice->use(4, *charlie);
    
    std::cout << "\nTesting unequip functionality:" << std::endl;
    AMateria* unequipped = m3;
    alice->unequip(2);
    
    std::cout << "\nVerifying unequip worked:" << std::endl;
    alice->use(2, *charlie);
    
    std::cout << "\nRe-equipping the unequipped materia:" << std::endl;
    alice->equip(unequipped);
    
    std::cout << "\nTesting deep copy of Character:" << std::endl;
    Character* aliceCopy = new Character(*alice);
    
    std::cout << "\nAlice and her copy using materias:" << std::endl;
    alice->use(0, *charlie);
    aliceCopy->use(0, *charlie);
    
    std::cout << "\nUnequipping from original and checking copy:" << std::endl;
    alice->unequip(0);
    alice->use(0, *charlie);
    aliceCopy->use(0, *charlie);
    
    std::cout << "\nCleaning up:" << std::endl;
    delete alice;
    delete aliceCopy;
    delete charlie;
    delete src;
    delete m5;
}

void testUnknownMateria() {
    std::cout << "\n===== UNKNOWN MATERIA TEST =====\n" << std::endl;
    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    
    AMateria* unknown = src->createMateria("fire");
    if (unknown == NULL) {
        std::cout << "Successfully returned NULL for unknown materia type" << std::endl;
    }
    
    delete src;
}

int main() {
    testSubjectExample();
    testAdditionalFunctionality();
    testUnknownMateria();
    
    return 0;
}
