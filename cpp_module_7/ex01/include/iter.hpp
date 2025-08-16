#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename Func>
void iter(T *array, size_t len, Func func)
{
	if (array == NULL)
		return ;
	
	for (size_t i = 0; i < len; i++)
	{
		func(array[i]);
	}
	
}

template <typename T>
void print(const T &x)
{
	std::cout << x << std::endl;
}

template <typename T>
void increment(T &x)
{
	++x;
}

#endif