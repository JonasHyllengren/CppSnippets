#pragma once

#include "Shape.h"
#include <string>

class Ellipse final : public Shape
{
public:
	Ellipse(double x = 0, double y = 0, double rx = 1, double ry = 1);
	double area() const override;
	void resize(double fact) override;
	std::string to_string() override;
private:
	double rx, ry;
};