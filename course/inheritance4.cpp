
// base class methods that should be overrided: virtual
// base class methods that shouln't be overrided are left as usual

// A class not intended to be a base class should not have any virtual members. 
// The class should be marked as final

// ****************** VIRTUAL METHODS AND DTORS ************************
#include <iostream>

class MyBase {
public:
	virtual void m(std::string s) {std::cout << s <<  " MyBase::m()\n";};
	MyBase() { this->m("base ctor"); } // a call from method to method uses the this pointer
	// this can be of the type MyDerived if the object is MyDerived
	// can we call m() in derived from the ctor for base? derived object doesn't exist when ctor for base is run
	// SOLUTION: All methods called from ctor and dtor are from the class of the ctor/dtor
	virtual ~MyBase() { this->m("base dtor"); }
};
class MyDerived : public MyBase{
public:
	void m(std::string s) override {std::cout << s << " MyDerived::m()\n";};
	MyDerived() : MyBase() {this->m("derived ctor");};
	~MyDerived() {this->m("derived dtor");};
};

void virtual_methods_and_ctors(){
   MyBase a{};
   MyDerived b{};
}

// ********************* ABSTRACT CLASSES ***************************

// Design dilemma:
// In the base class we want everything in the derived classes so that we can call thm from a base class pointer
// But we want to keep the base class small
// SOLUTION: Abstract methids
// makes it possible to add methods by name only
// syntax: "virtual [func] = 0;"
class MyAbstractBase {
public:
	virtual void m() = 0; // abstract
};
// derived classes must override all abstract members to become concrete
// RULE: Add a comment for the abstract stuff that you don't define in the derived class!

// ************ INTERFACES *****************
// An interface class contains only abstract methods
// no concrete stuff
// no member variables
#define interface struct // this is kind of ugly
interface IMyInterface {
	virtual void m1() const = 0;
	virtual int m2(int) = 0;
	// virtual ~IMyInterface() {}; // pre C++11
	virtual ~IMyInterface() = default; // C++11
};
// Contains only abstract methods and virtual destructor

//*********************** SAFE DOWNCASTING *****************************
// Risky, other changes my break stuff

class Shape {

};
class Rectangle : public Shape {

};

int main()
{
   {
      virtual_methods_and_ctors();
   }   
   
   
	Shape* fig = new Rectangle;
	// Pointers
	// Rectangle* r{ dynamic_cast<Rectangle*>(fig) };
	// Reference
	// Rectangle& r{ dynamic_cast<Rectangle&>(fig) };

	(Rectangle*)fig; // DONT DO THIS!


	return 0;
}

// ****************** CAST OPERATORS ***********************
/*
const_cast // removes const property
reinterpret_cast // more brutal
static_cast  // often used to explicitly do implicit type convertion
*/
// boh are for brutal type convertion. Takes place at compile time without checks
