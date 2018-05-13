// More pointers, this time with classes!
#include <iostream>

using namespace std;

class A{
   public:
      A(int a, int b): i1{a}, i2{b} {};
      int i1;
      int getI2(){
         return i2;
      }
   private:
      int i2;
};

int main(){
   A a(11,37);
   //A* p(9,45);
   A* p = &a;
   cout << "Using arrows: " << p->i1 << ", " << p->getI2() << endl;
   cout << "Using '*.'  : " << (*p).i1 << ", " << (*p).getI2() << endl;
   
   


}
