#ifndef _POW_HPP_
#define _POW_HPP_

#include <math.h>
#include "op.hpp"
using namespace std; 

class Pow : public Base {
	public: 
		Pow(Base* left, Base* right):Base() {
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
	private:
		string lstr;
		string rstr;
		double ldbl;
		double rdbl;
};

#endif
