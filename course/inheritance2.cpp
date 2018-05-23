#include <iostream>

class A
{
public:
	virtual void M() {
	//void M() {
		// M() is virtual from here and downwards in the class heirchy
		// "virtual" adds a function pointer to the object
		std::cout << "A::M()\n";
	}
};


class B : public A
{
public:
	void M() {
		std::cout << "B::M()\n";
	}
};
		// If A::M() is virtual, B::M() is also virtual. Setting it "virtual" explicitly doesn't add anything
		// Adding virtual here is bad style. 
		// In C++11, we can mark a function as overriding
class BOverride : public A
{
public:
	void M() override {
		std::cout << "BOverride::M()\n";
	}
};
		// This forces the compiler to check if the base class contains a matching function
class BFinal : public A
{
public:
	void M() final {
		std::cout << "BFinal::M()\n";
	}
};
		// "final" works as override + makes it imposible to override the function further
		// it is possible to mark entire classes final

class BFinalClass final : public A
{
	public:
	void M() {
		std::cout << "BFinalClass::M()\n";
	}
};

// If a base method shouldn't be overrided, make it non-virtual

int main()
{
   {
      std::cout << "Normal\n";
	   A* pa{ new A{} };
	   pa->M();
	   B* pb{ new B{} };
	   pb->M();
	   A* paorb{ new B{} };
	   paorb->M(); // If M() is virtual, tis print B. If not, this prints A
   }
   {
      std::cout << "Override\n";
	   A* pa{ new A{} };
	   pa->M();
	   BOverride* pb{ new BOverride{} };
	   pb->M();
	   A* paorb{ new BOverride{} };
	   paorb->M(); // If M() is virtual, tis print B. If not, this prints A
   }
   {
      std::cout << "Final\n";
	   A* pa{ new A{} };
	   pa->M();
	   BFinal* pb{ new BFinal{} };
	   pb->M();
	   A* paorb{ new BFinal{} };
	   paorb->M(); // If M() is virtual, tis print B. If not, this prints A
   }
   {
      std::cout << "Final Class\n";
	   A* pa{ new A{} };
	   pa->M();
	   BFinalClass* pb{ new BFinalClass{} };
	   pb->M();
	   A* paorb{ new BFinalClass{} };
	   paorb->M(); // If M() is virtual, tis print B. If not, this prints A
   }

}
// We use static binding, not dynamic binding
// since paorb is A* at compile time, we treat it as A*
// keyword "virtual" forces dynamic binding
// RULE: the fastest option is often defualt (e.g. static over dynamic)
