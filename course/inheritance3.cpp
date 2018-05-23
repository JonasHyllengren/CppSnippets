#include <iostream>

class myBase {
public:
	~myBase() {std::cout << "myBase dtor\n";};
};

class myDerived : public myBase{
public:
	~myDerived(){std::cout << "myDerived dtor\n";};
};


// ****************** FIX! **********************

#include <iostream>

class myBaseFixed {
public:
	virtual ~myBaseFixed() {std::cout << "myBaseFixed dtor\n";}; // Fix: Set as virtual!
};

class myDerivedFixed : public myBaseFixed {
public:
	~myDerivedFixed() {std::cout << "myDerivedFixed dtor\n";};
};

int main()
{
   {
	   myBase* m = new myDerived{};
	   delete m; // only calls the base destructor! DANGER!
   }
   { 
	   myBaseFixed* m = new myDerivedFixed{};
	   delete m; 
   }
}
// RULE: All base classes should have a virtual destructor!
// If no base class destructor is needed: make an empty one, or set as default (in C++11)
