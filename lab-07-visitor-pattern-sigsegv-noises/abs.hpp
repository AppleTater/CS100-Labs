
#ifndef ABS_HPP
#define ABS_HPP

#include "base.hpp"
#include "Decorator.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

using namespace std;

class Base;

class Abs : public Decorator {
	protected:
	public:
		Abs(Base* input) : Decorator() {value = input;}
		double evaluate(){return abs(value->evaluate());}
		string stringify(){};
		Base* get_left() {return value;}
    		Base* get_right() {return nullptr;}
    		Iterator* create_iterator() {
    			return new UnaryIterator(this);
    		}
		void accept(CountVisitor* vis) {
    			vis->visit_abs();
    		}
};

#endif
