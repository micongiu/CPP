#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack();
		MutantStack( const MutantStack &src );
		MutantStack &operator=( const MutantStack& src );
		~MutantStack();

		iterator begin();
		iterator end();
};

template<typename T>
MutantStack<T>::MutantStack()
{
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &src)
{
	*this = src;
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& src)
{
	std::stack<T>::operator=(src);
	return *this;
}

template<typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

#endif