
#include "stdafx.h"
#include "Ellipse.h"
#include <math.h>

#include <sstream>

Ellipse::Ellipse(double x, double y, double rx, double ry) :
	Shape(x, y), rx { rx }, ry{ ry } {}


double Ellipse::area() const {
	const double PI = 3.1415;
	return rx*ry*PI;
}

void Ellipse::resize(double fact)
{
	rx *= fact;
	ry *= fact;
}

std::string Ellipse::to_string() {
	std::ostringstream ss;
	ss << Shape::to_string() << " that is an ellipse with radii rx: " << rx << ", ry: " << ry << " and area: " << area();
	return ss.str();
}