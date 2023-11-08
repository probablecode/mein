#ifndef	ITER_HPP
#define	ITER_HPP
#include <iostream>
template <typename T>
void	iter(T *array, int length, void (*fn)(T &))
{
	for (int i = 0; i < length; i++)
		fn(array[i]);
}

template <typename T>
void	iter(T *array, int length, void (*fn)(T const &))
{
	for (int i = 0; i < length; i++)
		fn(array[i]);
}



#endif
