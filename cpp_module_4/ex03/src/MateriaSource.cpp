#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource created" << std::endl;
	for(int i = 0; i < 4; i++)
		this->_learnedMaterias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	std::cout << "MateriaSource created as a copy of MateriaSource" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src._learnedMaterias[i])
			this->_learnedMaterias[i] = src._learnedMaterias[i]->clone();
		else
			this->_learnedMaterias[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=( const MateriaSource& src )
{
	std::cout << "MateriaSource assignation operator called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_learnedMaterias[i])
				delete this->_learnedMaterias[i];
			if (src._learnedMaterias[i])
				this->_learnedMaterias[i] = src._learnedMaterias[i]->clone();
			else
				this->_learnedMaterias[i] = NULL;
		}
	}
	return (*this);
};

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destroyed" << std::endl;
	for (int i = 0; i < 4; i++)
		delete _learnedMaterias[i];
};

void MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
	{
		return ;
	}
	
	for (int i = 0; i < 4; i++)
    {
        if (this->_learnedMaterias[i] == NULL)
        {
            std::cout << "MateriaSource learned: " << materia->getType() << std::endl;
            this->_learnedMaterias[i] = materia;
            return;
        }
    }
    std::cout << "MateriaSource: inventory is full." << std::endl;
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this-> _learnedMaterias[i] && this-> _learnedMaterias[i]->getType() == type)
		{
			std::cout << "MateriaSource: " << type << " created." << std::endl;
			return (this->_learnedMaterias[i]->clone());
		}
	}
	std::cout << "MateriaSource: " << type << " not found." << std::endl;
	return (NULL);
}

