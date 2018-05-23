
#include "stdafx.h"

#pragma once

#include <cstddef> // std::size_t

#include <iostream>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <functional>
#include <initializer_list>

template <typename T>
class my_vector
{
public:
	using value_type = T; 

	explicit my_vector(std::size_t size, const value_type& init = value_type());
	my_vector(const my_vector& rh);
	my_vector(std::initializer_list<value_type> list);
	my_vector(my_vector&& rh);
	~my_vector();

	my_vector& operator=(my_vector rh);

	std::size_t size() const; // const for reasons described in the next module
	void swap(my_vector other);

	template<class Comparator> // yet another type parameter!
	void sort(Comparator cmp);

	void print();

	const value_type& operator[](std::size_t i) const;
	value_type& operator[](std::size_t i);
	
	using iterator = value_type * ;
	using const_iterator = const value_type *;

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;

private:
	std::size_t theSize;
	value_type* pVec;
};

// ********************** START OF .CPP ********************************************************

template <typename T>
typename my_vector<T>::iterator my_vector<T>::begin() {
	return pVec;
}

template <typename T>
typename my_vector<T>::iterator my_vector<T>::end() {
	return (pVec + theSize);
}

template <typename T>
typename my_vector<T>::const_iterator my_vector<T>::begin() const {
	return pVec;
}

template <typename T>
typename my_vector<T>::const_iterator my_vector<T>::end() const {
	return pVec + theSize;
}

// ***************** SPECIAL MEMBER FUNCTIONS

template <typename T>
my_vector<T>::my_vector(std::size_t size, const value_type& init /*= value_type()*/) :
	theSize(size), pVec(new value_type[theSize])
{
	for (std::size_t i(0); i < theSize; ++i)
	{
		pVec[i] = init;
	}
}

template <typename T>
my_vector<T>::my_vector(const my_vector& rh) :
	theSize(rh.theSize), pVec(new value_type[theSize])
{
	std::cout << "copy ctor\n";
	for (std::size_t i(0); i < theSize; ++i)
	{
		pVec[i] = rh.pVec[i];
	}
}

template <typename T>
my_vector<T>::my_vector(my_vector&& rhs) :
	theSize(rhs.theSize), pVec(rhs.pVec)
{
	std::cout << "move ctor\n";
	rhs.pVec = nullptr;
	rhs.theSize = 0;
}

template <typename T>
my_vector<T>::my_vector(std::initializer_list<value_type> list) : theSize{ list.size() }, pVec(new value_type[theSize]) {
	int i = 0;
	for (auto v : list) {
		pVec[i] = std::move(v);
		++i;
	}
}

template <typename T>
my_vector<T>::~my_vector()
{
	delete[] pVec;
}

template <typename T>
my_vector<T>& my_vector<T>::operator=(my_vector rhs)
{
	std::cout << "copy/swap assignment\n";
	// basic way
	/*
	delete pVec;
	pVec = rhs.pVec;
	rhs.pVec = nullptr;
	theSize = rhs.theSize;
	return *this;
	*/
	// copy-and-swap way
	swap(rhs);
	return *this;
}

template <typename T>
void my_vector<T>::swap(my_vector other) {
	std::swap(pVec, other.pVec);
	std::swap(theSize, other.theSize);
}

/**************** UTIL ************************************************/

template <typename T>
std::size_t my_vector<T>::size() const
{
	return theSize;
}

template <typename T>
void my_vector<T>::print() {
	for (std::size_t i(0); i < theSize; ++i)
	{
		std::cout << pVec[i] << " ";
	}
	std::cout << std::endl;
}


template <typename T>
template <typename Comparator>
void my_vector<T>::sort(Comparator cmp) // copy-paste into the my_vector class
{    // bubblesort
	if (theSize < 2)
		return;
	bool swapped;
	do
	{
		swapped = false;
		for (size_t i{ 0 }; i < theSize - 1; i++)
		{
			//if (pVec[i + 1] < pVec[i]) // replace < for a callback
			if (cmp(pVec[i + 1], pVec[i])) 
			{
				std::swap(pVec[i], pVec[i + 1]);
				swapped = true;
			}
		}
	} while (swapped);
}

/*********** INDEX OPERATORS ********************/

template <typename T>
const typename my_vector<T>::value_type& my_vector<T>::operator[](std::size_t x) const {
	if ((x >= 0) && (x<theSize)) {
		return pVec[x];
	}
	throw std::out_of_range{"Nu blev det fel..."};
}

template <typename T>
typename my_vector<T>::value_type& my_vector<T>::operator[](std::size_t x) {
	return const_cast<my_vector::value_type&>((static_cast<const my_vector&>(*this))[x]);
}

/*********** BOOL OPERATORS **************/

template <typename T>
bool operator==(const my_vector<T>& v1, const my_vector<T>& v2) {
	if (v1.size() != v2.size()) {
		return false;
	}
	else {
		for (std::size_t i = 0; i<v1.size(); ++i) {
			if (v1[i] != v2[i]) {
				return false;
			}
		}
	}
	return true;
}

template <typename T>
bool operator!=(const my_vector<T>& v1, const my_vector<T>& v2) {
	return !(v1 == v2);
}

template <typename T>
bool operator<(const my_vector<T>& v1, const my_vector<T>& v2) {
	std::size_t min_size{ std::min(v1.size(), v2.size()) };
	for (std::size_t i = 0; i < min_size; ++i) {
		if (v1[i] < v2[i]) {
			return true;
		}
	}
	return false;
}

template <typename T>
bool operator>(const my_vector<T>& v1, const my_vector<T>& v2) {
	return !((v1 < v2) || (v1 == v2));
}

template <typename T>
bool operator<=(const my_vector<T>& v1, const my_vector<T>& v2) {
	return !(v1 > v2);
}

template <typename T>
bool operator>=(const my_vector<T>& v1, const my_vector<T>& v2) {
	return !(v1 < v2);
}