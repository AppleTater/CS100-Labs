#include "gtest/gtest.h"
#include "VectorContainer.hpp"
#include "ListContainer.hpp"
#include "SelectionSort.hpp"
#include "BubbleSort.hpp"
#include "add.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "rand.hpp"

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
}
