#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <string>

using namespace std;
class Op : public Base {
	private:
		double val;
	public:
		Op(double value) : Base() { val = value; }
		virtual double evaluate() { return val; }
		virtual std::string stringify() { 
			int toString = static_cast<int>(val);
			string output = to_string(toString);
			return output;
		 }
};

#endif //__OP_HPP__
