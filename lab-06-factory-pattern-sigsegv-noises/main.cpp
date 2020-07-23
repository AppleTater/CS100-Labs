
#include <iostream>
#include <string>
#include <math.h>
#include <string>
#include <list>
#include <vector>

#include "factory.hpp"
#include "add.hpp"
#include "base.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "sub.hpp"


using namespace std;


int main (int argv, char** argc) {
	Factory* mainTest = new Factory();
	Base* output = mainTest->parse(argc, argv);

	if (output == nullptr) {
		cout << "null pointer\n";
	} else {
		cout << "String: " << output->stringify() << endl;
		cout << "Number: " << output->evaluate() << endl;
	}

	return 0;
}
