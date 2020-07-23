#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "op.hpp"
#include <iostream>
#include <string>
#include "iterator.hpp"
#include "visitor.hpp"

using namespace std;

class Add : public Base {
	public:
		Add(Base* left, Base* right) : Base() {
			left_child = left;
			right_child = right;
			lStr = left -> stringify();
			rStr = right -> stringify();
			lNum = left -> evaluate();
			rNum = right -> evaluate();
		}
		virtual double evaluate() {
			return(lNum + rNum);
		}
		virtual string stringify() {
			return (lStr + " + " + rStr);
		}
		Base* get_left() {
			return left_child;
		}
     		Base* get_right() {
			return right_child;
		}
     		Iterator* create_iterator() {
     		Iterator* it = new BinaryIterator(this);
     			return it;
     		}
     		void accept(CountVisitor* vis) {
     			vis->visit_add();
     		}
	private:
		string lStr;
		string rStr;
		double lNum;
		double rNum;
		Base* left_child;
		Base* right_child;
};
#endif	
