#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _learnedMaterias[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& src);
		MateriaSource& operator=(const MateriaSource& src);
		~MateriaSource();
		
		void learnMateria(AMateria* materia);
		AMateria* createMateria(const std::string& type);
};

#endif
