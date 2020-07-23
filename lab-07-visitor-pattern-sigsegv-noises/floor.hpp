#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "base.hpp"
#include "Decorator.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

using namespace std;

class Base;

class Floor : public Decorator {
    protected:
    public:
    Floor(Base* input) : Decorator() {value = input;}
    double evaluate(){return floor(value->evaluate());}
    string stringify(){};
    Base* get_left() {return value;}
    Base* get_right() {return nullptr;}
    Iterator* create_iterator() {
        return new UnaryIterator(this);
    }
    void accept(CountVisitor* vis) {
        vis->visit_floor();
    }
};

#endif
