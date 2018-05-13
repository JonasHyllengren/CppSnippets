#include <iostream>
#include <vector>

using namespace std;

class A{ // has default ctor
   public: 
      A(): i{0} {};
      A(int temp): i{temp} {};
   private:
      int i;
};

class B{ // misses default ctor
   public: 
      B(int temp): i{temp} {};
   private:
      int i;
};

int main(){

   A a(3);
   B b(4);

   A a1;
   // B b1; // Not Ok since no default ctor exists! 
   
   // a1.A(3); // Tries to call the ctor again. Not ok!
   
   A a2(); // WARNING: This declares a function! 
   
   A aa4[4]; 
   // B ab[4]; // Not Ok since no default ctor exists!
   
   // std::vector
   vector<A> va; 
   vector<B> vb; // This is ok
   vector<B> vb2 = {b, b, b, b}; // Also ok!
   
}
