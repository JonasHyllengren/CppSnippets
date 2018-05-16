#include "MyVector.h"
#include <iostream>

int main(){
   MyVector v1{7,5};
   MyVector v2{7,5};
   v1.print();
   if (v1==v2){
      std::cout << v1[4] << std::endl;
   }
   v1[4] = 2;
   if (v1==v2){
      v1.print();
   }


}
