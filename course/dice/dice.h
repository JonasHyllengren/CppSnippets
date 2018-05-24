#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

class seedClass {
public:
	seedClass();
	void helloWorld();
};

class dice {
public:
	dice();
	int roll();
	int value() const;
private:
	int v;
	static seedClass seed;
};
