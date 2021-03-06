
class A {
private:
	class B {	// Nested class declaration

	};
// This is only "useful" if the nested class is protected or private
// example of nested class: vector::iterator (public, defined like this is for style)
};

// school book example
class List {
public:
	List();
	void insert(int n) { head = new Node{ n, head } };
private:
	class Node {
	private: 
		int data;
		Node* next;
	public:
		Node(int d, Node* n = 0) : data{ d }, next{ n } {};
	};

	Node* head;
};

/******************************* ALIAS TYPENAMES************************************************/
// typedef int value_type; // define a synonym "value_types" that are changed for "int" at compile time.
// close to "define" but not pre-processor
// define A B -> replaces A with B. typedef A B -> replaces B with A. Confusing :s

// in C++11: using value_type = int; // This is nicer, also better for templates

/***********************************STATIC MEMBERS *******************************************/
class hasStaticMember {
	static int a;
	// a is not part of the object
	// a is some kind of mutant between member and global variable
	// private: static -> a global variable that only a certain class can access. Nicer.
	// static int a; // In old c++, this is an declaration. a must be defined and initlialized somewhere else!
};

// static objects are created as the program loads. Their constructor executes BEFORE main
class HasStaticMember {
	static A a;
};
// When is the constructor for A run? Before main()? RULE: The constructor must be run before main() starts!
// IF there are multiple such objects, their order is undefined!

// This is useful for classes that must be initialized before use but were we cannot trust the user to do that. 

enum{zero, one, five = 5};
// this defines a nameless! enum. Can be done inside a class if you need "global" data. 
enum class Color {red, blue, green};
// "enum class" is the type catogry!
// works as enums were inteded
// int x = Color::blue; // compile error
// use "enum class"

/*********************************** STATIC METHODS **************************************************/
// behaves like a global function. Doesn't have a this pointer
// MyClass::MyStaticFunction();
// obj.MyStaticFunction(); // This is also ok. obj will not be affected!
// static methods can access static variables but not member variables!

/*********************************** REFERENCE MEMBERS ***************************************/
class HasReferencesMember {
	A& obj;
public:
	HasReferencesMember(A& arg) : obj{ arg } {};

	// references are always turned to pointers by the compiler
	// The references must be initialized and cannot be changed

	// The reference must be initiliazed -> no default ctor
	// no default assignment

	// arg must survive MyClass object, or we will crash

};

/***********************************CONST MEMBERS AND METHODS *************************************************/
// Works almost as reference members!
class HasConstMember{
	const int n; // if initialized here, the ctor cannot change it, and it migt as well be static!
public:
	HasConstMember(int i) : n{ i } {};
}
// The const must be initiliazed -> no default ctor
// no default assignment

class HasConstMemberFunc {
public:
	void func() const; // func may not change the object state except for members declared mutable!
	// func can be called for const objects of MyClass. If func isn't const, IT CANNOT BE RUN for const objects!
};

// SomeClass& noObj{const_cast<SomeClass&>(obj)};
// fixes that functions havn't been declared const

/********************************* CONSTEXPRS *********************************************/
// constexpr is a stronger version of const
// consexprs is assigned at cmpile time
constexpr b{ 7 }; // ok
constexpr bb{ b }; // also ok
constexpr cc{ my_constexpr_function() }; // ok
// More constexpr and const -> better


/****************** MUTABLE ***************************/
// mutable
// mutable overrides const
// a mutable member of a const object can be overwritten!

/*************************** AUTO *******************************/
// auto cannot be used with brace init! 
// auto i{5}; // i will be an std::initializer_list
// c++17 changes this. There the compiler gets that a single argument shouldn't be an initializer list




int main()
{
    return 0;
}

