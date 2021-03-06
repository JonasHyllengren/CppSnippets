
//********************** OPERATOR OVERLOADING ****************************
// Operattor-överlagring
// define operators such as "+" for our own classes
// non-member/free function

// not overloaded: "sizeof", "::", ".", ".*", "?:", "typeid"
// size operator, scope, dot, dotstar, 

// MUST BE MEMBERS
// "=", "[]", "->", "()"

// operator is a function called "operatorX"
// return type is free, types of parameters are also free
// The number of arguments are predfeined

// "-x" unary
// "x - y" binary

// Precedence cannot be changed
// Associativity cannot be changed as well. 
// (everything goes left-to-right except "=" wich goe right-to-left)

// Commutivity ((a+b)==(b+a))
// This causes problems if we make the function as a member. 
// SOLUTION: Make a free function

// DRAWBACK: free functions must often be declared "friend"

//******************** SPECIAL CASES **********************
// PRE- AND POST-FIX
// "++" and "--" has two types: postfix and prefix
// prefix - returns the new value
++t; // T& operator++(T&);
// postfix - returns the old value
t++; // const T& operator++(T&, int); // int IS NEVER USED, it is only a flag

// INDEX OPERATOR - takes elements from set
// We want it to be able to be an lvalue
// obj = set[5];
// set[6] = obj; // How do we do this!? Function call to the left of assignment!?
// return values of functions are lvalues if they are references to class objects (but not if they are primitives or by-value objects!)

// Ok, but what if the object is const?
// If we declare the index operator const, we can change const sets
// SOLUTION: Define two index operators, one for const
const X& MyClass::operator[] (Y y) const {
	// boundary checking
	// find and return an element as const
}
const X& MyClass::operator[] (Y y) { // no const
	return const_cast<X&>((static_cast<const MyClass&>(*this))[y]); // uses const version
}

// POINTER OPERATOR
T::operator-> () // makes classes that behaves like pointers
T::operator* () // makes classes that behaves like pointers

S T::operator() (X, Y, Z, ...);
T obj; obj(...)

// new and delete can be assigned to improve memory allocation
// increases performance since we dont need OS calls to get memory

int main()
{
    return 0;
}

