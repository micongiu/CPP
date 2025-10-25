#include "Array.hpp"

template <typename T>
Array<T>::Array() : len(0)
{
	this->array = new T[len];
}

template <typename T>
Array<T>::Array( unsigned int n ) : len(n)
{
	this->array = new T[len];
}

template <typename T>
Array<T>::Array( const Array &src ) : len(src.len)
{
	this->array = new T[len];
	for (size_t i = 0; i < len; i++)
		this->array[i] = src.array[i];
}

template <typename T>
Array<T>& Array<T>::operator=( const Array &src )
{
	if (this == &src)
		return (*this);

	if (this->arr)
		delete[] this->array;

	this->len = src.len;
	this->array = new T[len];
	for (size_t i = 0; i < len; i++)
		this->array[i] = src.array[i];
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->array;
}

template <typename T>
T& Array<T>::operator[]( size_t idx ) const
{
	if (idx >= this->len)
		throw std::out_of_range("Index out of range");
	return (this->array[idx]);
}

template <typename T>
size_t Array<T>::size() const
{
	return (this->len);
}