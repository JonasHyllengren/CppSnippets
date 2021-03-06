#include "dice.h"

// define seed outside of file!
// die::init die::i{};  // definition of the static member

seedClass::seedClass() {
	std::cout << "seedClass ctor called\n";
	std::srand(static_cast<int>(std::time(0)));
};

void seedClass::helloWorld() {
	std::cout << "Hello World!\n";
}

// seedClass dice::seed;
// seedClass seed;
/************* DICE ****************/

dice::dice() : v { 0 } {}

int dice::roll() {
	v = rand() % 6 +1; // gets random value from seed
	return v;
}

int dice::value() const {
	return v;
}
