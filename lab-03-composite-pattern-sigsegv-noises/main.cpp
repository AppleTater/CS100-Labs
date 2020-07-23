#include <iostream>

#include "base.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "rand.hpp"
#include "pow.hpp"

int main() {
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(add, two);

    std::cout << minus->stringify() << " = " << minus->evaluate() << std::endl;

   Base* six = new Op(6);
   Base* eight = new Op(8);
   Base* fifteen = new Op(15);

   Base* zero = new Op(0);

  // Base* random = new (rand);
   Base* div = new Div(six, two);
   Base* pow = new Pow(fifteen, div);
   Base* addition = new Add(pow, eight);

   Base* sub = new Sub(addition, fifteen);

  std::cout << sub->stringify() << " = " << sub->evaluate() << std::endl;
 
    return 0;
}
