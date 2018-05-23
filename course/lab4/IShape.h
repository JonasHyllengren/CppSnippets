#pragma once

// interface class IShape

#define interface struct

#include <string>


interface IShape
{
public:
	virtual void move(int dx, int dy) = 0;
	virtual double area() const = 0;
	virtual void resize(double fact) = 0;
	virtual std::string to_string() = 0;
	virtual ~IShape() = default;
};