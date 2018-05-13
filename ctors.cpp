// Examples of constructors

#include <iostream>

using namespace std;

class A{
   public:
      A(int temp){
         i = temp;
         d = 4.2;
         s = "bil";
      }
      A(double temp): d{temp}, i{2}, s{"hej"} {}; // list initialization, nicer
      A(string s){
         // A string means that I want to use int 1 to initialize!
         A(1); // ERROR: This creates a new A object. We cannot call the int ctor like this!
         // We must rewrite the code or use delegating ctors!
         i = 1;
         d = 5.3;
         s = "cykel";
      }
      


   private:
      int i;
      double d;
      string s;
};

int main(){
   A a1(11);
   A a2(3.14);
   A a3("test");
   
}
