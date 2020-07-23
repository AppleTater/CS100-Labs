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
#include "floor.hpp"
#include "abs.hpp"
#include "ceil.hpp"
#include "paren.hpp"
#include "trunc.hpp"

int main() {
	Op* op1 = new Op(7);
	Op* op2 = new Op(4.5);
	Op* op3 = new Op(3);
	Op* op4 = new Op(200);
	Mult* A = new Mult(op1,op2);
	Add* B = new Add(op3,A);
	Sub* C = new Sub(B,op4);



	cout << "Before Ceiling: " << endl;
	cout << A->evaluate() << endl;
	cout << "After Ceiling: " << endl;
	Ceil* A1 = new Ceil(A);
	cout << A1->evaluate() << endl;

	cout << "Before Floor: " << endl;
	cout << B->evaluate() << endl;
	cout << "After Floor: " << endl;
	Floor* B1 = new Floor(B);
	cout << B1->evaluate() << endl;

	cout << "Before Absolute Value: " << endl;
	cout << C->evaluate() << endl;
	cout << "After Absolute Value: " << endl;
	Abs* C1 = new Abs(C);
	cout << C1->evaluate() << endl;

	Op* op5 = new Op(-5);
	Op* op6 = new Op(2);
	Pow* pow1 = new Pow(op5, op6);

	Op* op7 = new Op(4);
	Op* op8 = new Op(9);
	Mult* mult1 = new Mult(op7, op8);

	Add* add1 = new Add(pow1, mult1);

	Op* op9 = new Op(17);

	Sub* D = new Sub(add1, op9);

	cout << "Before Parentheses: " << endl;
	cout << D->stringify() << endl;

	Op* opb5 = new Op(-5);
	Op* opb6 = new Op(2);
	Pow* powb1 = new Pow(opb5, opb6);

	Op* opb7 = new Op(4);
	Op* opb8 = new Op(9);
	Mult* multb1 = new Mult(opb7, opb8);
	Paren* D1 = new Paren(multb1);
	Add* addb1 = new Add(powb1, D1);

	Op* opb9 = new Op(17);

	Sub* BD = new Sub(addb1, opb9);

	cout << "After Parentheses: " << endl;
	cout << BD->stringify() << endl;

	Op* op10 = new Op(78);
	Op* op11 = new Op(5);
	Op* op12 = new Op(100);
	Mult* mult3 = new Mult(op10, op11);
	Add* E = new Add(op12, mult3);
	cout << "Before truncation: " << endl;
	cout << E->stringify() << endl;

	Op* op101 = new Op(78);
	Op* op111 = new Op(5);
	Op* op121 = new Op(100);
	Mult* mult31 = new Mult(op101, op111);
	Trunc* E1 = new Trunc(mult31);
	Add* BE = new Add(op121, E1);

	cout << "After truncation: " << endl;
	cout << BE->stringify() << endl;

	return 0;
}
