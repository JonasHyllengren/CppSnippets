#include <iostream>

using namespace std;

void printI(int i){
   cout << i << endl;
}

void printP(int* i){
   cout << i << endl;
}

int main(){

   int a{2};         // a is an integer
   int* p = &a;      // p is an integer pointer pointing at a
   
   cout << a << endl;   // print a
   cout << &a << endl;  // print adress of a
   cout << p << endl;   // print adress of a again
   cout << *p << endl;  // print a again

   // Do the same thing as above with functions
   cout << "Now with functions!" << endl;  
   printI(a);
   printP(&a);
   printP(p);
   printI(*p);
}
