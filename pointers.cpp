#include <iostream>

using namespace std;

int main(){

   int a{2};         // a is an integer
   int* p = &a;      // p is an integer pointer pointing at a
   
   cout << a << endl;   // print a
   cout << &a << endl;  // print adress of a
   cout << p << endl;   // print adress of a again
   cout << *p << endl;  // print a again


}
