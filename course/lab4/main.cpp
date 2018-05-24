
// "typeid(*this).name()" returns the name of the class (as a cha*)

// pekare till abstrakta klasser är ok men inte object.
// IShape* shapes[500]{}; // ok
// Ishape shape; // error

#include "Ellipse.h"
#include "Triangle.h"

#include <iostream>

class Test {};

int main()
{
	Ellipse e1(1, -2, 1.3, 6.7);
	e1.move(3, -4);
	e1.resize(0.3);
	std::cout << e1.to_string() << std::endl;

	Triangle t1(1, -2, 1.3, 6.7);
	t1.move(3, -4);
	t1.resize(0.3);
	std::cout << t1.to_string() << std::endl;


    return 0;
}

