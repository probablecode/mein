#include <iostream>

typedef struct Data	data;

typedef struct Data
{
	std::string	data;
}	Data;

uintptr_t	serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
Data	*deserialize(uintptr_t uptr)
{
	return (reinterpret_cast<Data *>(uptr));
}

int	main(int argc, char *argv[])
{
	if (argc == 2) 
	{
		uintptr_t	uptr;
		Data	data;
		Data	*dptr;

		data.data = argv[1];
		std::cout << "data.data : " << data.data << std::endl;
		uptr = serialize(&data);
		std::cout << "uptr : " << uptr << std::endl;
		std::cout << "&data : " << &data << std::endl;
		
		dptr = deserialize(uptr);
		std::cout << "dptr->data : " << dptr->data << std::endl;

		std::cout << "sizeof (Data) : " << sizeof(Data*) << std::endl;
		std::cout << "sizeof (uintptr_t) : " << sizeof(uintptr_t) << std::endl;

	}

	return (0);
}
