  
#ifndef __RAND_HPP__ 
#define __RAND_HPP__

#include "base.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>

class Rand : public Base {
	public:
		Rand() : Base () {
			num = rand() % 100;
			s_num = std::to_string(num);
			s_num.erase(s_num.find_last_not_of('0') + 1, std::string::npos);
			s_num.erase(s_num.find_last_not_of('.') + 1, std::string::npos);
		}
		virtual double evaluate() { return num; }
		virtual std::string stringify() {return s_num;}

	private:
		double num;
		std::string s_num;
};

#endif 
