
#include <iostream>

using namespace std;

void f(){cout<<"f\n";}

namespace A{
   void f(){cout<<"A\n";}
}

namespace B{
   void f(){cout<<"B\n";}
   
   namespace C{
   void f(){cout<<"C\n";}
   }
   
   class D{
      public:
      void f(){cout<<"D\n";}
   };
   
}

int main(){

   // Ok
   f();
   A::f();
   B::f();
   B::C::f();
   B::D d; d.f();
   
   // Not ok
   // C::f();
   // D d2; d2.f();
   // D::d.f();
   
   ::f();  
   
}
