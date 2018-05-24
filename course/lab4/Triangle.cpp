
#include "Triangle.h"
#include <math.h>

#include <sstream>

Triangle::Triangle(double x, double y, double sx, double sy) :
	Shape(x, y), sx{ sx }, sy{ sy } {}


double Triangle::area() const {
	return sx*sy/2;
	//return (rx * ry * 3.1415^2);
}

void Triangle::resize(double fact)
{
	sx *= fact;
	sy *= fact;
}

std::string Triangle::to_string() {
	std::ostringstream ss;
	ss << Shape::to_string() << " that is an triangle with sides sx: " << sx << ", sy: " << sy << " and area: " << area();
	return ss.str();
}
