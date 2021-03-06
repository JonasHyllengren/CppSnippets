
#include <iostream>

// move assignment is used for temporary rvalues
// functions that return temporary objects
// ctors return temporary objects

/**************** MOVE SEMANTICS ****************/
// lvalue: has name, will continue existing
// rvalue: temporary, will soon die (can be on the left side)

// When the thing we are copying/assigning from will die soon, we want move semantics!
// "&&" = "rvalue reference". Can only refer to a temporary object! 

class A {
public:
	A() = default;
	A(const A&) = default;
	A& operator=(A&& a) // Not const since we want to steal resources from a! 
	{ 
		std::cout << "move assignment\n";
		return a;
	}
};

A foo() {
	A a;
	return a;
}

void f1(const A& arg); // lvalue or rvalue
void f2(A& arg); // can only be called lvalue
void f3(A&& arg); // can only be called with rvalue

// Sometimes we want to assign to an rvalue INSIDE the function. This is ok.
// But we can get problems with forwarding. 
// We can e.g. recieve an rvalue into an function and send it to another function as an lvalue

// we might need std::move in the lab since the compiler might remove move assignment

// move assignment. basic: free resource, repoint pointer, remove pointer. Advanced: swap all members, delete
// swap() exists in the std:lib

// the compiler adds move ctor and assignment, IF there is no explicit copy, assign or destructor.

/********************* UNIFORM INITILIAZATION **********************/
// or "bracket initlialization"
// int myarr[4] = {1, x, x+1, 0}; // Ok in C
// struct MyStruct mys = {1, "hej", 4.5}; / Ok in C
// Lets steal this to C++! We should use this everywhere!
// C++ syntax removes the "="
// struct MyStruct{string s, int i, double d};
// MyStruct obj{"abs", 1, 1.5}; // as if MyStruct had a ctor (but it doesn't!)

// You can call a ctor with brackets. There's no truncation (good!)

/*
int i = 1.8; // truncates to 1
int i(1.8);  // truncates to 1
int i{1.8}; // compile error (good!)
int i{}; // default value of int is 0
int x(); // defines a function!
*/

/*
MyClass obj{"A", 65, 63.3};
obj = {"B", 2, 1.7}; // implicit constructor call!
obj = MyClass{"B", 2, 1.7}; // This is less confusing!
obj == {"B", 2, 1.7}; // This is also ok
*/

/*********************** INITIALIZER_LIST **************************/
// A class in the std::lib

// make a ctor that takes an initliazer list

/******************************************************************/
// SINGLE ARGUMENT CTORS SHOULD BE MARKED AS EXPLICIT UNLESS WE HAVE GOOD REASONS TO DO OTHERWISE





int main()
{
	A a1 = foo(); // move ctor
	a1 = foo(); // move assignment
}

