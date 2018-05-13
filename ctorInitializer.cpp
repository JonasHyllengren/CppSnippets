// Demonstrate the cases in which initialization MUST be used

class noDefaultCtor{
   public:
      noDefaultCtor() = delete;
      noDefaultCtor(int i) {};
};
 
class A{
   public:
      A(int a1, int& a2, noDefaultCtor a3): t{a1}, r{a2}, o{a3} {};
      A(int a1, int& a2, noDefaultCtor a3, int notUsed){
         t = a1; // Compile error
         r = a2; // Compile error
         o = a3; // Compile error
      };
   private:
      const int t = 9   ; // const
      int& r; // reference
      noDefaultCtor o; // object with no default ctor    
      // superclass with no ctor
};

int main(){
   noDefaultCtor o(1);
   int i1{1}, i2{2};
   A a(i1, i2, o);
}
