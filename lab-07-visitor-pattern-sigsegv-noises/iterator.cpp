#include <iostream>
#include <stack>

#include "iterator.hpp"
#include "base.hpp"

using namespace std;


void NullIterator::first() {
	return;
}

void NullIterator::next() {
	return;
}

bool NullIterator::is_done() {
	return true;
}

Base NullIterator::current() {
	return nullptr;
}

PreorderIterator::PreorderIterator(Base* ptr) {
	self_ptr = ptr;
	root = nullptr;
}

void PreorderIterator::first() {
	while(!iterators.empty()) {
		iterators.pop();
	}
	
	itPtr = self_ptr->create_iterator();
	itPtr->first();
	iterators.push(itPtr);
}

void PreorderIterator::next() {
	root = current();

	itPtr = iterators.top()->current()->create_iterator();

	itPtr->first();

	iterators.push(itPtr);

	while(!iterators.empty() && iterators.top()->is_done()) {
		iterators.pop();
		if(!iterators.empty()) {
			iterators.top()->next();
		}
	}
}

bool PreorderIterator::is_done() {
	if (iterators.empty()) {
		return true;
	}

	else {
		return false;
	}
}

Base* PreorderIterator::current() {
	root = iterators.top()->current();
	return root;
}
