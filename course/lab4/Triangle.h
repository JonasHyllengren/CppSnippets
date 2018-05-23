#pragma once
#pragma once

#include "Shape.h"
#include <string>

class Triangle final : public Shape
{
public:
	Triangle(double x = 0, double y = 0, double sx = 1, double sy = 1);
	double area() const override;
	void resize(double fact) override;
	std::string to_string() override;
private:
	double sx, sy;
};