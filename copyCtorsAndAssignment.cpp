#include <iostream>

using namespace std;

class A{
   public: 
      A() = default;
      A(const A& a){
         cout << "constructor\n";
      };
      A& operator=(const A& rhs) {
         cout << "assignment\n";
      };
};

A f(A a){
   return a;
}

int main(){
   A a1, a2;

   // ctor   
   A a3(a1);
   A a4 = a1;
   
   // ass
   a2 = a1;
   
   // ctor ctor
   A a5 = f(a1);
   // ctor ctor ass
   a2 = f(a1);

   
}
