#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "base.hpp"
#include "Decorator.hpp"

using namespace std;

class Base;

class Floor : public Decorator {
    protected:
    public:
    Floor(Base* input) : Decorator() {value = input;}
    double evaluate(){return floor(value->evaluate());}
    string stringify(){};
};

#endif
