#include "Base.hpp"

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base::~Base() {}

Base *generate(void)
{
	short r = rand();
	if (r % 3 == 0)
		return new A();
	if (r % 2 == 0)
		return new B();
	return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p)) { std::cout << "A"; }
	if (dynamic_cast<B *>(p)) { std::cout << "B"; }
	if (dynamic_cast<C *>(p)) { std::cout << "C"; }
	std::cout << " class identified through pointer." << std::endl;
}

void identify(Base& p) {
	try {
		A &cast = dynamic_cast<A &>(p);
		std::cout << "A";
		static_cast<void>(cast);
	} catch (std::exception &e){}
	try {
		B &cast = dynamic_cast<B &>(p);
		std::cout << "B";
		static_cast<void>(cast);
	} catch (std::exception &e){}
	try {
		C &cast = dynamic_cast<C &>(p);
		std::cout << "C";
		static_cast<void>(cast);
	} catch (std::exception &e){}
	std::cout << " class identified by reference.\n";
}
