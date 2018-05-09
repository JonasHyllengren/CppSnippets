#include <iostream>

using namespace std;

/*
void f(const int a){
   cout << a << " by value" << endl;
};
*/

// f(int& a) is ambiguous with f(const int a)
// & = reference
void f(int& a){
   cout << a << " by reference" << endl;
};

// f(int&& a) is NOT ambiguous with f(const int a)
// && = rvalue reference
void f(int&& a){
   cout << a << " by rvalue reference" << endl;
};


int main(){

   int a = 3;
   f(a);   // ambiguous f(int) vs f(int&)
   f(4); // ambiguous f(int) vs f(int&&)

}
