#include <iostream>
using namespace std;
#include <vector>
#include <list>

#include "BubbleSort.hpp"
#include "SelectionSort.hpp"
#include "div.hpp"
#include "ListContainer.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "VectorContainer.hpp"
#include "add.hpp"
#include "base.hpp"
#include "container.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "sort.hpp"


int main() {
	Op* op1 = new Op(8);
	Op* op2 = new Op(9);
	Op* op3= new Op(2);
	Op* op4= new Op(5);
	Op* op5= new Op(8.7);
	Mult* A = new Mult(op1,op2);
	Add* B = new Add(op3,A);
	Sub* C = new Sub(B,op4);
	Div* D = new Div(C,op4);
	VectorContainer* container = new VectorContainer();
	container->add_element(A);
	container->add_element(B);
	container->add_element(C);
	container->add_element(D);

	cout << "The expression A located at index 0 evaluates to: " << container->at(0)->evaluate() << endl;
 	cout << "The expression B located at index 1 evaluates to: " << container->at(1)->evaluate() << endl;
	cout << "The expression C located at index 2 evaluates to: " << container->at(2)->evaluate() << endl;
	cout << "The expression D located at index 3 evaluates to: " << container->at(3)->evaluate() << endl;
	cout << "Container Before Sort: " << endl;
 	container->print();

 	cout << "Container After Sort: " << endl;
 	container->set_sort_function(new SelectionSort());
 	container->sort();
 	container->print();

	cout << "The expression A located at index 0 evaluates to: " << container->at(0)->evaluate() << endl;
 	cout << "The expression B located at index 1 evaluates to: " << container->at(1)->evaluate() << endl;
	cout << "The expression C located at index 2 evaluates to: " << container->at(2)->evaluate() << endl;
	cout << "The expression D located at index 3 evaluates to: " << container->at(3)->evaluate() << endl;

	return 0;
}
