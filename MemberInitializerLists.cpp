#include <iostream>

using namespace std;

class A1{
   public:
      A1(int a, int b, double c) : x(a), y(b), z(c)  {} // Use member initialise list
      void print(){
         cout << x << " " << y << " " << z << endl;
      }
   protected:
      int x;
      int y;
      int z;
};


class A2{
   public:
      A2(int a, int b, double c){
         x = a;
         y = b;
         z = c; // Use assignment in constructor. This is inferior since x, y, and z is default initiliased before the assignment. 
      }
      void print(){
         cout << x << " " << y << " " << z << endl;
      }
   protected:
      int x;
      int y;
      int z;
};

// A3 is same as A1 but uses extended initializer list
class A3{
   public:
      A3(int a, int b, double c) : x{a}, y{b}, z{c}  {} // compiler warning
      void print(){
         cout << x << " " << y << " " << z << endl;
      }
   protected:
      int x;
      int y;
      int z;
};

int main(){
   A1 a1(3.1, 4, 5.1); // This casts 3.1 to int (=3). This is avoided if you use braces for initiliazation!
                       // But since c is a double, 5.1 is ok. Casting is done by the constructor (bad!). 
   //A1 a1alt{3.1, 4, 5.1}; // This fails at compile time as it stops 3.1->int. Good!
   A3 a3alt(3.1, 4, 5.1); // This is ok. :(
   A2 a2(7, 8, 9.1);
   A3 a3(15, 16, 17.1);
   
   a1.print(); 
   // a1alt.print();
   a3alt.print();
   a2.print();
   a3.print();
}
