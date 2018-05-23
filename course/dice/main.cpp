
#include <iostream>
#include "dice.h"


/******************* TEST CODE ************************/

void print_dice(const dice& d)
{
	std::cout << d.value() << " ";
}

int main()
{
	dice d1{};
	for (unsigned i{ 0 }; i < 20; i++)
	{
		print_dice(d1);
		d1.roll();
	}
	std::cout << std::endl;

	dice d2{};
	for (unsigned i{ 0 }; i < 20; i++)
	{
		print_dice(d2);
		d2.roll();
	}
	std::cout << std::endl;
}
