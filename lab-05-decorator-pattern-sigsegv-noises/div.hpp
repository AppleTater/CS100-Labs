  
#ifndef _DIV_HPP_
#define _DIV_HPP_

#include "op.hpp"

using namespace std;

class Div : public Base {
	public:	
		Div(Base* left, Base* right) : Base() {
			lStr = left -> stringify();
			rStr = right -> stringify();
			lNum = left -> evaluate();
			rNum = right -> evaluate();
		}
		virtual double evaluate() {
			return (lNum / rNum);
		}
		virtual string stringify() {
			return (lStr + " / " + rStr);
		}
	private:
		string lStr;
		string rStr;
		double lNum;
		double rNum;
};
#endif
