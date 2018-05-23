#pragma once

#include "IShape.h"
#include <string>

class Shape : public IShape
{
public:
	Shape(int x = 0, int y = 0);
	void move(int dx, int dy) override;
	std::string to_string() override;

private:
	int x, y;
};