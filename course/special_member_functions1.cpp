// ********** EXPLICIT DEFAULT CTOR ********************************
class classWithExplicitDefaultCtor {
public:
	classWithExplicitDefaultCtor(); // Explicitly assign default ctor
	classWithExplicitDefaultCtor(int i) {}; // Another ctor...
};

// ********** BAD COPY CTOR ********************************
/*
class classWithBadCopyCtor {
	classWithBadCopyCtor newObj = classWithBadCopyCtor(const classWithBadCopyCtor oldObj) {};
	// This copy ctor doesn't take a reference!
	// This means that oldObj must be copied into the function. 
	// That calls the copy ctor. This means that the object must be copied 
	// ->copy ctor etc. add naseum. StackOwerflow.
};
*/

// ********** IMPLICIT CONVERTION ********************************
// Single argument constructors are implicit converters!
class implicitConverter {
public:
	implicitConverter(int i) {}; 
};

void foo(implicitConverter x) {}

void implicitConvertionIsDoneHere() {
	foo(3); // This is ok! 3 is converted to implicitConverter by the ctor!
}

class fixedClass {
	explicit fixedClass(int i) {};
};

// ********** CALLING CTORS FROM CTORS ********************************
// This is only possible in C++11 or later
class MyClass {
	int a;
public:
	MyClass(int x) : a(x) {};
	MyClass() : MyClass(0) {}; // This is ok in C++11! 
	// ctors can only be called from the init list
	// Design rule: Implement the most complicated ctor, call it from the other ctors!
};

// ********** DESTRUCTORS ********************************
class destructorClass {
public:
	destructorClass() {
		p = new int[10];
	}
	~destructorClass() { // never takes arguments // can be called explicitly!
		delete[] p;
	}
	int* p;
};

// destructor is ALWAYS called when objects go out of scope (on stack)
// destructor is ALWAYS called when temporary objects go out of scope

void foo1() {
	destructorClass x;
	destructorClass* p = new destructorClass();
	delete p; // calls destructor
	p->~destructorClass(); // calls destructo explicitly
} // destructor is run here since x goes out of scope

// RAI : Resource acquisition is initialization

// ********** ASSIGNMENT ********************************
class assignmentClass {
	assignmentClass& operator=(const assignmentClass& rhs) {};

};
// copy ctor is needed to pass objects to functions
// copy assignment is needed to be C compatible
//     since class and struct in C is the same thing
//     in C, structs can be assigned to eachother
//     assignment doesn't exist in java. How does that work?

// == isn't provided by default
//    it would feel like the other operators like '<' are missing

// lvalue can be assigned

// assignment should check if the two arguments are equal!
// assignment operator must be class member!
// "a = b;" -> "a.operator=(b);"
// "if (this != &rhs)" checks against self assignment

// "return *this" - returns the called object
// "this" is a pointer to the calling object, "*this" is the calling objects
// this is done to enable chaining e.g. "a=b=c"

// ******************** RECAP ************************
// Rule of Three: destructor, copy ctor, copy assignment. Need one -> Need all!



int main()
{
   ;
}
