#ifndef	EASYFIND_HPP
#define	EASYFIND_HPP
#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T	&container, int value)
{
	class	NoSuchValueException : public std::exception {
		const char *what() const throw () {
			const char *ret = "There's no corresponding value\n";
			return (ret);
		}
	};
	typename T::iterator iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
		throw (NoSuchValueException());
	else
		return (iter);
};

template <typename T>
typename T::const_iterator	easyfind(T	&container, int value)
{
	class	NoSuchValueException : public std::exception {
		const char *what() const throw () {
			const char *ret = "There's no corresponding value\n";
			return (ret);
		}
	};
	typename T::const_iterator iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
		throw (NoSuchValueException());
	else
		return (iter);
};
#endif
