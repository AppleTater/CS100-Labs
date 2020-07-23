#ifndef PARENTHESES_HPP
#define PARENTHESES_HPP

#include "base.hpp"
#include "Decorator.hpp"

using namespace std;

class Base;

class Paren : public Decorator {
	protected:
	public:
		Paren (Base* input) : Decorator() {value = input;}
		double evaluate(){ return value->evaluate();}
		string stringify(){
			string result = "(" + value->stringify() + ")";
			return result;
		}
};

#endif
