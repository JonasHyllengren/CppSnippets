#include <iostream>

using namespace std;


// Class with no special member functions
class A{
public:
   A() = delete; // remove default constructor
   A(A&) = delete; // remove copy constructor
   A(A&&) = delete; // remove move constructor
   A& operator=(A) = delete; // remve copy assignment operator
   A& operator=(A&&) = delete; // remove move assignment operator
   ~A() = delete; // remove default destructor 
};

// Tutorial classes
class B{
public:
   B() {cout << "B: Default constructor\n";};
   B(B&) {cout << "B: Copy constructor\n";};
   B(B&&) = delete; // delete move constructor
   B& operator=(B) {cout << "B: Copy assignment operator\n";};
   //B& B::operator=(B&) {cout << "B: Copy assignment operator when 'copy-and-swap' idiom cannot be used\n";};
   B& operator=(B&&) = delete; // delete move assignment operator 
   ~B() {cout << "B: Default destructor\n";};
private:
   int v_;
};
   
class C{
public:
   C() {cout << "C: Default constructor\n";};
   C(C&) = delete; // delete copy constructor
   C(C&&) {cout << "C: Move constructor\n";};
   //C& operator=(C) = delete; // copy assignment cannot be deleted since that blocks move assignment :S
   C& operator=(C&&) {cout << "C: Move assignment operator\n";}; 
   ~C() {cout << "C: Default destructor\n";};
};
   
C foo(C c) {return c;}

int main(){
   B b1;
   B b2(b1);
   B b3 = b1;
   b2 = b3;
   
   C c1;
   C c2 = move(c1);
   C c3;
   c3 = foo(C()); // calling with c2-by-value creates ambiguous compile results if both copy and move assingment exists
   
}
