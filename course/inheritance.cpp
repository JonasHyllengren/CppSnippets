
#include <iostream>

class shape {
private: 
	int posX, posY;
public:
	shape(int px, int py) {};
	void draw() const {};
};

class ellipse : public shape {
	// "public" is "normal inheritance". This is not set by default!
private:
	int radiusX, radiusY; // exending
public:
	// the base class ctor is always run first.
	// when we look inside the ctor of the derived class, a base class ctor has been run
	// if this isn't done explicitly, the dafult base class ctor will be run
	// DESIGN RULE: Always call the base class ctor explicitly from the derived class ctor
	ellipse(int px, int py, int rx, int ry) : shape(1, 1) {};
	void draw() const {};
	void print_radius() const {};
};

void callStuff() {
	shape* p = new ellipse{1, 1, 2 , 3};
	p->draw(); // this is ok since shape has draw
// p->print_radius(); // this is not ok since shape doesn't have 

	// Base class should contain the functions of the derived classes, BUT the base class should be minimal!
	// SOLUTION: Abstract classes and interfaces
}

// Not inhereted: ctors, destructors, assignment operators (but the ocmpiler generets that calls these)
// Also: private member variables

class myBase {
public:
	myBase(int i) : baseMember{i} {}; // must be public!
	int baseMember;
};
class myDerived : public myBase {
	myDerived(int i, double d) : myBase{ i }, extendedMember{ d } {};
	double extendedMember;
};

// base class ctor must be called in init list
// avoid "protected" in the base class! Since it makes it possible to bypass the base class ctor

// Asssignment op in derived class
// IF resource allocation takes place, it usually is done only in the base class. 
// base class assignment op must be called from the derived assignment op EXPLICITLY
/* IN ASSIGNMENT OPERATOR
   if (this != &rhs) {
	   MyBase::operator=(rhs);
	   // This is bad syntax, this is the same syntax as calling a static!
	   y = rhs.y;
	   // take care of resources
   }
*/
// Combining overloading and overriding
// If the base classes has several overloadedfunctions
// And the derived class overrides one of them
// The other ones are "hidden" and cannot be used
// Trick: add using (using makes things visable)
// using MyBase::func <- Makes everything invisable called "func" in base class visable

// Inheriting Constructors (C++11)
// using Base:Base; // Makes Derived have same ctor set as Base
// Don't use: it makes way for future bugs

// ****************************** BASE CLASS ACCESS *********************************

// class MyDerived : public MyBase
// "normal inheritence"
// class MyDerived : protected MyBase // public members become protected
// class MyDerived : private MyBase
// public and protected base class members become private
// private inheritense is very similiar to private aggregation
// private/protected inheritence is implementation, not interface
// private is default "D : private B" = "D : B"

// EXTENDED SCOPE
/*
public:
	using B::bpub;
	using B::bprot;
	using B::bpriv; // error
*/
// A reason to not use protected: it can be made public!

// ************************************** MULTIPLE INHERITANCE ********************************************
// use if you have good reasons...
// stream operator uses multiple inheritance
// class C : public A, public B {...}
// Problems: name collisions. Multiple base ctors must be called.
// How are the base objects laid out in memory?
// What if I have base class pointers?
class A{};
class B{};
class C : public A, public B {};

int main(){
C* pC{ new C{} };
A* pA{ pC };
B* pB{ pC };
}
// one of pA or pB will NOT be equal to pC! (which one is undefined)
// "if (this != &rhs)" doesn't work!
