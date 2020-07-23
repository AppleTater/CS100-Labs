#ifndef BUBBLESORT_CPP
#define BUBBLESORT_CPP

#include "container.hpp"
#include "sort.hpp"

using namespace std;

class BubbleSort : public Sort {
	public:
		BubbleSort(){};

		virtual void sort(Container* container) {
		int i, j;
		int size = container->size();
		for(i = 0; i < size -1; ++i)
			for(j = 0; j < size - i - 1; j++) {
				if(container->at(j)->evaluate() > container->at(j+1)->evaluate()) {
					container->swap(j, j+1);
				}
			}
		}
};

#endif
