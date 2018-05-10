#include <iostream>
using namespace std;

// https://www.geeksforgeeks.org/scope-resolution-operator-in-c/

int x; // global x

class A{
   public:
      void f(); // only declaration
};

void A::f(){cout<<"This function is defined outside of A!\n";}

int main(){
   int x = 3;
   cout << x << endl; // local x
   cout << ::x << endl; // global x
   A a;
   a.f();
   
}
