
#ifndef _VECTOR_CONTAINER_HPP_
#define _VECTOR_CONTAINER_HPP_

#include "sort.hpp"
#include "base.hpp"
#include "container.hpp"

#include <iostream>
#include <vector>

using namespace std;

class VectorContainer : public Container {
	private:
		vector <Base*> v;
	
	public:
		VectorContainer() {sort_function = nullptr;}
		VectorContainer(Sort* function) {sort_function = function;}

		virtual void add_element(Base* element) {
			v.push_back(element);
		}

		virtual void print() {
			for (unsigned int i = 0; i < v.size(); i++) {
				cout << "Tree " << i + 1 << ": " << v.at(i)->stringify() << endl;
			}
		}

		virtual void sort() {
			if (sort_function == nullptr) {
				throw string ("No algorithm present");
			}
			
			else {
				sort_function->sort(this);
			}	
		}

		virtual void swap(int i, int j) {
			Base* temporary = v.at(i);
			v.at(i) = v.at(j);
			v.at(j) = temporary;
		}

		virtual Base* at(int i) {
			if (i < 0) {
				throw string ("Value is < 0");
			}
			else if (i > this->size()) {
				throw string ("Value is > size");
			}
			return v.at(i);
		}

		virtual int size() {
			return v.size();
		}
};
#endif
