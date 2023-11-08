#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
template <typename T>
class Array
{
	private	:
		T	*arr;
		unsigned int	len;
		T	noMeans;
		class IndexOutOfBound : public std::exception {
			const char	*what() const throw() {
				const char	*ret = "[Exception Occur] : Index is out of bound\n";
				return (ret);
			}
		};
	public	:
		Array() : arr(nullptr), len(0) {
			std::cout << "Array<type T>'s default constructor is called\n";};
		Array(unsigned int n) : len(n) {
			arr = new T[n];
			std::cout << "Array<type T>[" << n\
				<<"]'s constructor is called and array address : " << arr << std::endl;
			for (unsigned int i = 0; i < len; i++)
				std::cout << arr[i];
			std::cout << std::endl;
		}
		Array	&operator=(const Array &ref)
		{
			std::cout << "Array<type T>'s assignment is operated\n";
			if (this->arr)
				delete (this->arr);
			this->len = ref.len;
			this->arr = new T[this->len];
			for (unsigned int i = 0; i < this->len; i++)
				this->arr[i] = ref.arr[i];
			return (*this);
		}
		Array(const Array &copy)
		{
			std::cout << "Array<type T>'s copy constructor is called\n";
			this->arr = nullptr;
			*this = copy;
		}
		~Array() {
			delete []arr;
			std::cout << "Array<type T>'s destructor is called\n";
		}
		T	&operator[](int index)
		{
			if (index < 0 || (int)len <= index)
				throw Array::IndexOutOfBound();
			return (arr[index]);
		}
		T const	&operator[](int index) const
		{
			if (index < 0 || (int)len <= index)
				throw Array::IndexOutOfBound();
			return (arr[index]);
		}	
		unsigned int	size(void) const {return (len);}
};
#endif
