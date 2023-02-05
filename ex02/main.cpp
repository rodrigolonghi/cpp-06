#include "Base.hpp"

int main() {
	Base *bPtr = generate();
	Base &rPtr = *bPtr;

	identify(bPtr);
	identify(rPtr);
	delete bPtr;
	return (0);
}
