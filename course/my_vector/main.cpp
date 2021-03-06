
#include "my_vector.h"

#include <iostream>
#include <algorithm>
#include <string>
#include <utility>

#include <memory>

template <typename T>
class my_vector_owner
{
	my_vector<T> vec;
public:
	my_vector_owner() : vec{ 100 } {}
	// add a set method using universal reference
	// note: moving copyctr and assign op generated by compiler
	template <typename ur>
	void set(ur&& v) {
		vec = std::forward<ur>(v);
	}
	void print() {
		vec.print();
	}
};

class A {
	int i;
public:
	A() = default;
	A(int a) : i { a } {};
	int get() {
		return i;
	}
};

int main()
{
	my_vector<int> v{ -3, 8, 13, 1, 0 , 0, -2, 61 };
	for (auto& i : v) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

	/*
	my_vector<std::shared_ptr<A>> v{ 10 };
	for (auto& i : v) {
		i = std::shared_ptr{};
	}
	*/

	/*
	my_vector_owner<int> mvo;
	my_vector<int> v{ 10 };
	v[0] = 5; v[1] = 2; v[2] = -3; v[4] = 9; v[5] = 3;
	mvo.set(v); // should cause copying of the argument
	mvo.print();
	v.print();
	mvo.set(my_vector<int>{ 20 }); // should cause moving of the argument

	
	for (auto& i : v) {
		std::cout << i << std::endl;
	}

	std::sort(v.begin() + 1,v.end());

	for (auto& i : v) {
		std::cout << i << std::endl;
	}
	*/



/*
my_vector<int> create_my_vector() {
	my_vector<int> v{ 5,11 };
	return v;
}

// global function
bool compare(std::string a, std::string b) {
	return a > b;
 }

// function class
class mySizeComparer {
public:
	bool operator() (const std::string a, const std::string b) {
		return a.size() < b.size();
	}

};


int main() {
	
	if (false){
		my_vector<int> v1{ 4,3 };
		my_vector<int> v2{ v1 }; // copy ctor
		v2[1] = 2;
		v1 = v2; // copy assignment
		v1.print();
		my_vector<int> v3{ create_my_vector() }; // move ctor
		v1 = create_my_vector(); // move ctor + move assignment
		v1.print();
	
	}
	// ************ OVERLOADING ************
	if (false){
		my_vector<int> v1{ 5,7 };
		std::cout << v1[2] << std::endl;
		v1[3] = 4;
		v1.print();
		my_vector<int> v2{ 5,7 };
		std::cout << (v1>=v2) << std::endl;
		v2[3] = 4;
		std::cout << (v1>v2) << std::endl;
	}

	// ******** SORT *******

	my_vector<std::string> v1{ 8, "gul*bil" };
	v1[0] = "abcd";
	v1[1] = "*Hej jag heter Jan!*";
	v1[2] = "tre";
	v1[3] = "a";
	v1[4] = "2432da&&&";
	v1.print();

	//std::function<bool(int a, int b)> func{};
	//func = [] (int a, int b) {return std::abs(a)<std::abs(b); }; // replaces "<"
	//auto func{ [](auto a, auto b) {return std::abs(a)<std::abs(b); } };

	mySizeComparer obj;


	// LAMBDA
	auto lambda{ [](auto a, auto b) {return std::size(a)>std::size(b); } };
	
	// std::function OBJECT
	std::function<bool(std::string a, std::string b)> func{lambda};
	
	
	
	v1.sort(func);
	v1.print();

}
*/
