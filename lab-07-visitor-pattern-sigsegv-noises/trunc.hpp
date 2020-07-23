#ifndef __TRUNCATE_HPP__
#define __TRUNCATE_HPP__

#include "base.hpp"
#include "op.hpp"
#include "Decorator.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

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
		Base* get_left() {return value;}
    		Base* get_right() {return nullptr;}
    		Iterator* create_iterator() {
    			return new UnaryIterator(this);
    		}
    		void accept(CountVisitor* vis) {
    			vis->visit_trunc();
    		}
};

#endif
