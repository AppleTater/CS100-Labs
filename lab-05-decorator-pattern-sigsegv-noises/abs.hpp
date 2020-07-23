#ifndef ABS_HPP
#define ABS_HPP

#include "base.hpp"
#include "Decorator.hpp"

using namespace std;

class Base;

class Abs : public Decorator {
	protected:
	public:
		Abs(Base* input) : Decorator() {value = input;}
		double evaluate(){return abs(value->evaluate());}
		string stringify(){};
};

#endif
