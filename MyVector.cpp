#include "MyVector.h"
#include <iostream>


MyVector::MyVector(int size, int init) : size{size} {
   for (int i = 0; i<size; ++i){
      p[i] = init;
   }
}
MyVector::MyVector(MyVector& init) {}
MyVector::~MyVector() {
   //delete []p;
   //p = nullptr;
}
MyVector& MyVector::operator=(const MyVector& v) {}

void MyVector::print() {
   for (int i = 0; i<size; ++i){
      std::cout << p[i] << " ";
   }
   std::cout << std::endl;
}

int& MyVector::operator[](int x){
   if ((x >= 0) && (x<size)){
      return p[x];
   }
   return p[0]; // todo: erro
}

bool operator==(const MyVector& v1, const MyVector& v2){
   if (v1.size != v2.size){
      return false;
   }else{
      for (int i = 0; i<v1.size; ++i){
         if (v1.p[i] != v2.p[i]){
            return false;
         }
      }
   }
   return true;
}
