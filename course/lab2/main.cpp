#include "my_vector.h"

int main()
{
	my_vector v1(7,1); // seven values assigned to 1
	my_vector v2(11, 54);
	
	v1.print();
	v2.print();
	
	my_vector v3(v1); // needs copy ctor
	v1 = v2; // needs assignment

	v3.print(); // should be same as original v1
	v1.print(); // should be same as original v2
    return 0;
}

// int() // returns the default value for int (i.e. 0)
