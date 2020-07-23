#ifndef _SELECTION_SORT_HPP_
#define _SELECTION_SORT_HPP_

#include "container.hpp"
#include "sort.hpp"
#include <vector>

using namespace std;

class SelectionSort : public Sort {
	public:
		SelectionSort() {};

		virtual void sort(Container* container) {
			int min, i, j;
			int size = container->size();

			for(i = 0; i < size - 1; i++) {
				min = i;
				for (j = i + 1; j < size; j++) {
					if (container->at(j)->evaluate() < container->at(min)->evaluate()) {
						min = j;										}
				}
				container->swap(min, i);
			}
		}

};

#endif
