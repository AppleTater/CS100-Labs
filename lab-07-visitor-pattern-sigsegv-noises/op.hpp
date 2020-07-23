
#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"
#include <string>

using namespace std;

class Op : public Base {
	private:
		double val;
		string str;
	public:
		Op(double value) : Base() {
			val = value;
			str = to_string(val);
			str.erase(str.find_last_not_of('0') + 1, string::npos);
			str.erase(str.find_last_not_of('.') + 1, string::npos);
		}
		virtual double evaluate() { return val; }
		virtual std::string stringify() {return str;}
		Base* get_left() {return nullptr;}
        	Base* get_right() {return nullptr;}
        	Iterator* create_iterator() {
        		Iterator* it = new NullIterator(this);
        		return it;
        	}
        	void accept(CountVisitor* vis) {
        		vis->visit_op();
        	}
};

#endif //__OP_HPP__
