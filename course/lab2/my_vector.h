#pragma once

#include "stdafx.h"
#include <cstddef> // std::size_t

class my_vector {
public:
	typedef int value_type; // the element type, now int
	explicit my_vector(std::size_t size, const value_type& init = value_type());
	my_vector(const my_vector& v);
	~my_vector();

	my_vector& operator=(const my_vector& v);

	std::size_t size() const; // const for reasons described in the next module

	void print();
private:
	std::size_t theSize;
	value_type* pVec; // value_type*
};
