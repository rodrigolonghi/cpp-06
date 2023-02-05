#ifndef DATA_HPP
#define DATA_HPP

#include <stdint.h>

typedef struct Data
{
	int	content;
} Data;

uintptr_t	serialize(Data* ptr);
Data*	deserialize(uintptr_t raw);

#endif
