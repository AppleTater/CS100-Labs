#ifndef ListContainer_H
#define ListContainer_H
#include "sort.hpp"
#include "base.hpp"
#include "container.hpp"
#include <list>
using namespace std;
class ListContainer : public Container {
	private:
		list<Base*> lcontainer;
	public:
		ListContainer() : Container() {};
		ListContainer(Sort* func)  {sort_function = func;};

 		void add_element(Base* element) {
			lcontainer.push_back(element);
		}
		void print(){
 		    int count = 0;
			for(list<Base*>::iterator it = lcontainer.begin(); it != lcontainer.end(); it++){
				cout << "Tree " << count + 1 << ": " << (*it)->stringify() << endl;
			}
		}
		void sort(){
			if(sort_function == nullptr){
				throw string("No sorting algorithm present");
			}
			sort_function->sort(this);
		}
		virtual void swap(int i, int j) {
            auto first = std::next(lcontainer.begin(), i);
            auto second = std::next(lcontainer.begin(), j);
            std::iter_swap(first, second);
        }
		virtual Base* at(int i){
			if(i < 0){
				throw string("Inputted value is less than 0");
			}
			int counter = 0;
			for(list<Base*>::iterator it = lcontainer.begin(); it != lcontainer.end(); it++){
				if(counter == i){
					return *it;
				}
				counter++;
			}
			throw string("Inputted value is bigger than the size of the tree");
		}

		virtual int size(){
			int counter = 0;
			for(list<Base*>::iterator it = lcontainer.begin(); it != lcontainer.end(); it++){
				counter++;
			}
			return counter;
		}
};
#endif
