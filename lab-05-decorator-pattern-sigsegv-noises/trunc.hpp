#ifndef __TRUNCATE_HPP__
#define __TRUNCATE_HPP__

#include "base.hpp"
#include "op.hpp"
#include "Decorator.hpp"

using namespace std;

class Base;

class Trunc : public Decorator {
	protected:
	public:
		Trunc(Base* input) : Decorator() {value = input;}
		double evaluate() {return value->evaluate();}
		string stringify() {
			Op* temp = new Op(value->evaluate());
			return temp->stringify();
		}
};

#endif
