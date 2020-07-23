#ifndef _SUB_HPP_
#define _SUB_HPP_

#include "op.hpp"

using namespace std; 

class Sub : public Base {
	public:
		Sub(Base* left, Base* right) : Base() {
			lstr = left->stringify();
			rstr = right->stringify();
			ldbl = left -> evaluate();
			rdbl = right -> evaluate();
		}
		virtual double evaluate() {
			return(ldbl - rdbl);
		}
		virtual string stringify() {
			return(lstr + " - " + rstr);
		}
	private:
		string lstr;
		string rstr;
		double ldbl; 
		double rdbl; 
};

#endif
