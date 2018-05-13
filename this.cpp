#include <iostream>

using namespace std;

class A{
   public:
      A(int i){
         this->i = i;
      }
      int get(){
         int i = 2;
         cout << "Local i: " << i << endl;
         cout << "A:s i: " << this->i << endl;
         return this->i;
      }
      void printA();
      void printA(A* a){
         cout << "Using A:s print: " << a->get() << endl;
      };
   private:
      int i;
};

void printA(A* a){
   cout << "Using function print: " << a->get() << endl;
}

void A::printA(){
   printA(this); // A:s print method
   ::printA(this); // print function
}

int main(){
   A a(3);
   a.printA();
   
   A b(4);
   a.printA(&b);
}
