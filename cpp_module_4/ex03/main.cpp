#include "include/MateriaSource.hpp"
#include "include/Character.hpp"
#include "include/Ice.hpp"
#include "include/Cure.hpp"

int main()
{
	std::cout << " == Test 0: MateriaSource creation and Materias learning" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "\n\n== Test 1: Character 'me' creation" << std::endl;
	ICharacter* me = new Character("me");
	
	std::cout << "\n\n== Test 2: AMaterias creation and equip" << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "\n\n== Test 3: Character 'bob'" << std::endl;
	ICharacter* bob = new Character("bob");

	std::cout << "\n== Test 4: 'me' use Materias on 'bob'" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\n\n== Test 5: Equipping beyond the limit ==" << std::endl;
	AMateria* ice1 = src->createMateria("ice");
	AMateria* cure2 = src->createMateria("cure");
	AMateria* extraMateria = src->createMateria("ice");

	me->equip(ice1);
	me->equip(cure2);
	me->equip(extraMateria);

	std::cout << "\n\n== Test 6: Testing a non-existing slot ==" << std::endl;
	me->use(4, *bob);

	std::cout << "\n\n== Test 7: Try to equip the same Materia instance twice ==" << std::endl;
	AMateria* sameMateria = src->createMateria("ice");
	me->equip(sameMateria);
	me->equip(sameMateria);

	std::cout << "\n\n== Test 9: Unknown Materia creation ==" << std::endl;
	AMateria* unknownMateria = src->createMateria("fire");
	if (unknownMateria == NULL)
		std::cout << "Unknown Materia not created as expected" << std::endl;
	else
		std::cout << "Error: Unknown Materia should return nullptr" << std::endl;


	std::cout << "\n== Destroying the objects ==" << std::endl;
	delete bob;
	delete me;
	delete src;
	delete extraMateria;
	delete sameMateria;
	delete unknownMateria;

	return 0;
}