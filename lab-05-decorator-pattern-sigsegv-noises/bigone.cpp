#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <math.h>

using namespace std;

class Sort;
class Base;
class Container;
class SelectionSort;
class BubbleSort;
class VectorContainer;
class ListContainer;

class Base {
    public:
        /* Constructors */
        Base() { };

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual string stringify() = 0;
};

class Op : public Base {
	private:
		double val;
	public:
		Op(double value) : Base() { val = value; }
		virtual double evaluate() { return val; }
		virtual std::string stringify() { 
			int toString = static_cast<int>(val);
			string output = to_string(toString);
			return output;
		 }
};

class Add : public Base {
	public:
		Add(Base* left, Base* right) : Base() {
			lStr = left -> stringify();
			rStr = right -> stringify();
			lNum = left -> evaluate();
			rNum = right -> evaluate();
		}
		virtual double evaluate() {
			return(lNum + rNum);
		}
		virtual string stringify() {
			return (lStr + " + " + rStr);
		}
	private:
		string lStr;
		string rStr;
		double lNum;
		double rNum;
};

class Sub : public Base {
	public:
		Sub(Base* left, Base* right) : Base() {
			lstr = left->stringify();
			rstr = right->stringify();
			ldbl = left -> evaluate();
			rdbl = right -> evaluate();
		}
		virtual double evaluate() {
			return(ldbl - rdbl);
		}
		virtual string stringify() {
			return(lstr + " - " + rstr);
		}
	private:
		string lstr;
		string rstr;
		double ldbl; 
		double rdbl; 
};

class Mult : public Base {
	public:
		Mult(Base* left, Base* right) : Base() {
			lStr = left -> stringify();
			rStr = right -> stringify();
			lNum = left -> evaluate();
			rNum = right -> evaluate();
		}
		virtual double evaluate() {
			return (lNum * rNum);
		}
		virtual string stringify() {
			return (lStr + " * " + rStr);
		}
	private:
		string lStr;
		string rStr;
		double lNum;
		double rNum;
};

class Div : public Base {
	public:	
		Div(Base* left, Base* right) : Base() {
			lStr = left -> stringify();
			rStr = right -> stringify();
			lNum = left -> evaluate();
			rNum = right -> evaluate();
		}
		virtual double evaluate() {
			return (lNum / rNum);
		}
		virtual string stringify() {
			return (lStr + " / " + rStr);
		}
	private:
		string lStr;
		string rStr;
		double lNum;
		double rNum;
};


class Pow : public Base {
	public: 
		Pow(Base* left, Base* right):Base() {
			lstr = left -> stringify();
			rstr = right -> stringify();
			ldbl = left -> evaluate();
			rdbl = right -> evaluate();
		}
		virtual double evaluate() {
			return(pow(ldbl, rdbl));
		}
		virtual string stringify() {
			return(lstr + " ** " + rstr);
		}
	private:
		string lstr;
		string rstr;
		double ldbl;
		double rdbl;
};

class Ceil : public Base {
	protected:
		Base* child;
	public:
		Ceil() : child(NULL) {}
		Ceil(Base* num) : child(num){}
		double evaluate() {return ceil(child -> evaluate());}
		string stringify() {return ceil(child -> stringify());}
};


class Floor : public Base {
	protected:
		Base* child;
	
	public:
		Floor() : child(NULL){}
		Floor(Base* number): child(number){}
		double evaluate() {
			return floor(child -> evaluate());
		}

		string stringify() {
			return floor(child -> stringify());
		}
};

class Abs : public Base {
	protected:
		Base* child;
	
	public:
		Abs() : child(NULL){}
		Abs(Base* number) : child(number){}

		double evaluate() {
			return abs(child -> evaluate());
		}

		string stringify() {
			return abs(child -> stringify());
		}

};

class Trunc : public Base {
	protected:
		Base* child;
	public:
		Trunc() : child(NULL) {}
		Trunc(Base* num) : child(num){}
		string stringify() {
			return Trunc(child -> stringify());
		}

		double evaluate() {
			return Trunc(child -> evaluate());
		}
};

class Paren : public Base {
	protected:
		Base* child;
	public:
		Paren() : child(NULL) {}
		Paren(Base* num) : child(num){}
		string stringify() {
			return Paren(child -> stringify());
		}

		double evaluate() {
			return Paren(child -> evaluate());
		}
};

class Container {
    protected:
        Sort* sort_function;

    public:
        /* Constructors */
        Container() : sort_function(nullptr) {}
        Container(Sort* function) : sort_function(function) { };

        /* Non Virtual Functions */
        void set_sort_function(Sort* sort_function) { // set the type of sorting algorithm
		this->sort_function = sort_function;
	}
        /* Pure Virtual Functions */
        // push the top pointer of the tree into container
        virtual void add_element(Base* element) = 0;
        // iterate through trees and output the expressions (use stringify())
        virtual void print() = 0;
       // calls on the previously set sorting-algorithm. Checks if sort_function is not null, throw exception if otherwise
        virtual void sort() = 0;
        /* Essentially the only functions needed to sort */
        //switch tree locations
        virtual void swap(int i, int j) = 0;
        // get top ptr of tree at index i
        virtual Base* at(int i) = 0;
        // return container size
        virtual int size() = 0;
};

class Sort {
    public:
        /* Constructors */
        Sort(){
	};

        /* Pure Virtual Functions */
        virtual void sort(Container* container) = 0;
};

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
/*
TEST(VectorContainerTestSet, SwapTest) {
	// Setup the elements under test
	 Op* six = new Op(6);
	 VectorContainer* test_container = new VectorContainer();
	// Exercise some functionality of the test elements 
	 test_container->add_element(six);
 	 // Assert that the container has at least a single element 
 	 // otherwise we are likely to cause a segfault when accessing
         ASSERT_EQ(test_container->size(), 1);	
	 EXPECT_EQ(test_container->at(0)->evaluate(), 6);
}
TEST(VectorContainerTestSet, AddElement) {
	Op* one = new Op(1);
	Op* two = new Op(2);
	VectorContainer* test_container = new VectorContainer();
	test_container->add_element(one);
	test_container->add_element(two);
	ASSERT_EQ(test_container->size(), 2);
	EXPECT_EQ(test_container->at(0)->evaluate(),1);
	EXPECT_EQ(test_container->at(1)->evaluate(),2);
}
TEST(VectorContainerTestSet, Print) {
	Op* one = new Op(1);
	Op* two = new Op(2);
	Add* plus = new Add(one, two);
	VectorContainer* test_container = new VectorContainer();
	test_container->add_element(plus);
	string result = "1 + 2";
	ASSERT_EQ(test_container->size(), 1);
	cout << result << endl;
        test_container->print();
}
TEST(ListContainerTestSet, SwapTest) {
	Op* tenpteight = new Op(10.8);
        Op* hundredandfive = new Op(105);
        ListContainer* test_container = new ListContainer();
        test_container->add_element(tenpteight);
        test_container->add_element(hundredandfive);
        test_container->swap(0,1);
        ASSERT_EQ(test_container->size(), 2);
        EXPECT_EQ(test_container->at(0)->evaluate(), 105);
        EXPECT_EQ(test_container->at(1)->evaluate(), 10.8);
}
TEST(ListContainerTestSet, AddElement) {
	Op* one = new Op(1);
	Op* two = new Op(2);
	ListContainer* test_container = new ListContainer();
	test_container->add_element(one);
	test_container->add_element(two);
	ASSERT_EQ(test_container->size(), 2);
	EXPECT_EQ(test_container->at(0)->evaluate(),1);
	EXPECT_EQ(test_container->at(1)->evaluate(),2);
}
TEST(ListContainerTestSet, Print) {
	Op* one = new Op(1);
        Op* two = new Op(2);
        Add* plus = new Add(one, two);
        Op* three = new Op(3);
        Op* ten = new Op(10);
        Mult* times = new Mult(three, ten);
        ListContainer* test_container = new ListContainer();
        test_container->add_element(plus);
        test_container->add_element(times);
        string result1 = "1 + 2";
        string result2 = "3 * 10";
        ASSERT_EQ(test_container->size(), 2);
        cout << result1 << endl << result2 << endl;
        test_container->print();
}
TEST(SortTestSet, BubbleVectorTest) {
    Op* five = new Op(5);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(five, four);
    Op* eight = new Op(8);
    Op* two = new Op(2);
    Add* TreeB = new Add(eight, two);
    Op* ten = new Op(10);
    Op* three = new Op(3);
    Sub* TreeC = new Sub(ten, three);
    VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);
    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 20);
    EXPECT_EQ(container->at(1)->evaluate(), 10);
    EXPECT_EQ(container->at(2)->evaluate(), 7);
    container->set_sort_function(new BubbleSort());
    container->sort();
    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 7);
    EXPECT_EQ(container->at(1)->evaluate(), 10);
    EXPECT_EQ(container->at(2)->evaluate(), 20);
}
TEST(SortTestSet, BubbleListTest) {
    Op* five = new Op(5);
    Op* three = new Op(3);
    Mult* TreeA = new Mult(five, three);
    Op* ten = new Op(10);
    Op* nine = new Op(9);
    Add* TreeB = new Add(ten, nine);
    Op* eight = new Op(8);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(eight, six);
    ListContainer* container = new ListContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);
    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 15);
    EXPECT_EQ(container->at(1)->evaluate(), 19);
    EXPECT_EQ(container->at(2)->evaluate(), 2);
    container->set_sort_function(new BubbleSort());
    container->sort();
    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 2);
    EXPECT_EQ(container->at(1)->evaluate(), 15);
    EXPECT_EQ(container->at(2)->evaluate(), 19);
}
TEST(SortTestSet, SelectionVectorTest) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);
    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);
    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);
    VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);
    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);
    container->set_sort_function(new SelectionSort());
    container->sort();
    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 28);
}
TEST(SortTestSet, SelectionListTest) {
   Op* five = new Op(5);
   Op* three = new Op(3);
   Mult* TreeA = new Mult(five, three);
   Op* ten = new Op(10);
   Op* nine = new Op(9);
   Add* TreeB = new Add(ten, nine);
   Op* eight = new Op(8);
   Op* six = new Op(6);
   Sub* TreeC = new Sub(eight, six);
   ListContainer* container = new ListContainer();
   container->add_element(TreeA);
   container->add_element(TreeB);
   container->add_element(TreeC);
   ASSERT_EQ(container->size(), 3);
   EXPECT_EQ(container->at(0)->evaluate(), 15);
   EXPECT_EQ(container->at(1)->evaluate(), 19);
   EXPECT_EQ(container->at(2)->evaluate(), 2);
   container->set_sort_function(new SelectionSort());
   container->sort();
   ASSERT_EQ(container->size(), 3);
   EXPECT_EQ(container->at(0)->evaluate(), 2);
   EXPECT_EQ(container->at(1)->evaluate(), 15);
   EXPECT_EQ(container->at(2)->evaluate(), 19);
}
int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}*/
