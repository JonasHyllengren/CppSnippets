// My implementation

#include <iostream>
#include "my_vector.h"

my_vector::my_vector(std::size_t size, const value_type& init /* = value_type() */) :
	theSize(size), pVec(new value_type[theSize])
	// How much can we do in the init list?
	// we can call "new". We can call functions.

	// the init of "pVec" uses "theSize". This is ok since they are inited by the ordering in the class declaration

{
	for (std::size_t i(0); i < theSize; ++i)
	{
		pVec[i] = init;
	}
	// Can we call a class method from the ctor? YES! The objects and its members exist, but it is not in a valid state 
	std::cout << "Constructor: ";
	this->print();
}

my_vector::my_vector(const my_vector& rh) :
	theSize(rh.size()), pVec(new value_type[theSize])// copy ctor
{
	for (std::size_t i(0); i < theSize; ++i)
	{
		pVec[i] = rh.pVec[0]; // Can I use rh.pVec when pVec is private? YES! Class is important, not object!
	}
	// implement
}

my_vector::~my_vector() {
	delete [] pVec; // [] is needed
}

my_vector& my_vector::operator=(const my_vector& rhs) // assignment
{
	if (this != &rhs) {
		delete[] pVec;
		// This is bad exception handling. This is fixed by copy-swap
		theSize = rhs.size();
		pVec = new value_type[theSize];
		for (std::size_t i(0); i < theSize; ++i)
		{
			pVec[i] = rhs.pVec[0];
		}
	}
	return *this;
}

std::size_t my_vector::size() const
{
	return theSize;
}

void my_vector::print() {
	for (unsigned int i = 0; i < theSize; ++i) {
		std::cout << pVec[i] << " ";
	}
	std::cout << std::endl;
}
