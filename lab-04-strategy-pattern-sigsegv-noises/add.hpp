#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "op.hpp"

using namespace std;

class Add : public Base {
	public:
		Add(Base* left, Base* right) : Base() {
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
	private:
		string lStr;
		string rStr;
		double lNum;
		double rNum;
};
#endif	
