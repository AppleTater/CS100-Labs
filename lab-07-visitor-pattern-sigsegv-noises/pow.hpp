#ifndef _POW_HPP_
#define _POW_HPP_

#include <math.h>
#include "op.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

using namespace std; 

class Pow : public Base {
	public: 
		Pow(Base* left, Base* right):Base() {
			left_child = left;
			right_child = right;
			lstr = left -> stringify();
			rstr = right -> stringify();
			ldbl = left -> evaluate();
			rdbl = right -> evaluate();
		}
		virtual double evaluate() {
			return(pow(ldbl, rdbl));
		}
		virtual string stringify() {
			return(lstr + " ** " + rstr);
		}
		Base* get_left() {return left_child;}
		Base* get_right() {return right_child;}
		Iterator* create_iterator() {
			Iterator* it = new BinaryIterator(this);
			return it;
		}
		void accept(CountVisitor* vis) {
    			vis->visit_pow();
    		}
	private:
		string lstr;
		string rstr;
		double ldbl;
		double rdbl;
		Base* left_child;
		Base* right_child;
};

#endif
