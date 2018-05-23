
#include "stdafx.h"
#include "Shape.h"
#include <sstream>

Shape::Shape(int x, int y) : x{ x }, y{ y } {}

void Shape::move(int dx, int dy) {
	x += dx;
	y += dy;
}

std::string Shape::to_string() {
	std::ostringstream ss;
	ss << "A shape at position x: " << x << ", y: " << y;
	return ss.str();
}