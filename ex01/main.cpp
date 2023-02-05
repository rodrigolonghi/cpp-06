#include "Data.hpp"
#include <iostream>

int main(void)
{
	Data *d = new Data();
	uintptr_t serializedDataPointer;
	Data *deserializedDataPointer;

	d->content = 10;
	serializedDataPointer = serialize(d);
	deserializedDataPointer = deserialize(serializedDataPointer);
	std::cout << "Data content: " << d->content << std::endl;
	std::cout << "Serialized data: " << serializedDataPointer << std::endl;
	std::cout << "Deserialized data content: " << deserializedDataPointer->content << std::endl;

	delete d;
	return (0);
}
