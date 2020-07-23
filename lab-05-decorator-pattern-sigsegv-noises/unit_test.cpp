#include "gtest/gtest.h"
#include "Decorator.hpp"
#include "floor.hpp"
#include "abs.hpp"
#include "ceil.hpp"
#include "paren.hpp"
#include "trunc.hpp"
#include "BubbleSort.hpp"
#include "SelectionSort.hpp"
#include "div.hpp"
#include "ListContainer.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "VectorContainer.hpp"
#include "add.hpp"
#include "base.hpp"
#include "container.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "sort.hpp"
#include "trunc.hpp"

TEST(AbsTest, NegTest) {
	Op* op1 = new Op(-2.5);
  	Abs* test = new Abs(op1);
	EXPECT_EQ(test->evaluate(), 2.5);
}

TEST(AbsTest, NegMultTest) {
	Op* op1 = new Op(3);
  	Op* op2 = new Op(-9);
	Mult* mult = new Mult(op1, op2);
  	Abs* test = new Abs(mult);
	EXPECT_EQ(test->evaluate(), 27);
}

TEST(AbsTest, NegSubTest) {
	Op* op1 = new Op(3);
	Op* op2 = new Op(9);
	Sub* sub = new Sub(op1, op2);
	Abs* test = new Abs(sub);
	EXPECT_EQ(test->evaluate(), 6);
}

TEST(AbsTest, PosAddTest) {
	Op* op1 = new Op(3);
	Op* op2 = new Op(9);
	Add* add = new Add(op1, op2);
	Abs* test = new Abs(add);
	EXPECT_EQ(test->evaluate(), 12);
}

TEST(CeilTest, PosDecTest) {
	Op* op1 = new Op(2.5);
  	Ceil* test = new Ceil(op1);
	EXPECT_EQ(test->evaluate(), 3);
}

TEST(CeilTest, IntTest) {
	Op* op1 = new Op(3);
  	Ceil* test = new Ceil(op1);
	EXPECT_EQ(test->evaluate(), 3);
}

TEST(CeilTest, NegDecTest) {
	Op* op1 = new Op(-5.4);
	Ceil* test = new Ceil(op1);
	EXPECT_EQ(test->evaluate(), -5);
}

TEST(CeilTest, ZeroTest) {
	Op* op1 = new Op(0);
  	Ceil* test = new Ceil(op1);
	EXPECT_EQ(test->evaluate(), 0);
}

TEST(FloorTest, PosDecTest) {
	Op* op1 = new Op(2.5);
  	Floor* test = new Floor(op1);
	EXPECT_EQ(test->evaluate(), 2);
}

TEST(FloorTest, IntTest) {
	Op* op1 = new Op(3);
  	Floor* test = new Floor(op1);
	EXPECT_EQ(test->evaluate(), 3);
}

TEST(FloorTest, NegDeciTest) {
	Op* op1 = new Op(-5.4);
  	Floor* test = new Floor(op1);
	EXPECT_EQ(test->evaluate(), -6);
}

TEST(FloorTest, ZeroTest) {
	Op* op1 = new Op(0);
  	Floor* test = new Floor(op1);
	EXPECT_EQ(test->evaluate(), 0);
}

TEST(ParenTest, Test1) {
	Op* op1 = new Op(6);
  	Op* op2 = new Op(1);
  	Sub* sub1 = new Sub(op1, op2);
  	Paren* test = new Paren(sub1);
  	string result = "(6 - 1)";
	EXPECT_EQ(test->stringify(), result);
}

TEST(ParenTest, Test2) {
	Op* op1 = new Op(9);
  	Op* op2 = new Op(3);
  	Pow* pow1 = new Pow(op1, op2);
  	Paren* test = new Paren(pow1);
  	string result = "(9 ** 3)";
	EXPECT_EQ(test->stringify(), result);
}

TEST(ParenTest, ParenRight) {
	Op* op1 = new Op(4);
  	Op* op2 = new Op(3);
  	Op* op3 = new Op(5);
  	Sub* sub1 = new Sub(op1, op2);
  	Paren* p1 = new Paren(sub1);
  	Mult* test = new Mult(op3, p1);
  	string result = "5 * (4 - 3)";
	EXPECT_EQ(test->stringify(), result);
}

TEST(ParenTest, ParenLeft) {
  	Op* op1 = new Op(6);
  	Op* op2 = new Op(3);
  	Op* op3 = new Op(10);
  	Div* div1 = new Div(op1, op2);
  	Paren* p1 = new Paren(div1);
  	Add* test = new Add(p1, op3);
  	string result = "(6 / 3) + 10";
	EXPECT_EQ(test->stringify(), result);
}

TEST(TruncTest, Test1) {
	Op* op1 = new Op(9);
  	Op* op2 = new Op(1);
  	Sub* sub1 = new Sub(op1, op2);
  	Trunc* test = new Trunc(sub1);
  	string result = "8";
	EXPECT_EQ(test->stringify(), result);
}

TEST(TruncTest, Test2) {
	Op* op1 = new Op(2);
  	Op* op2 = new Op(4);
  	Pow* pow1 = new Pow(op1, op2);
  	Trunc* test = new Trunc(pow1);
  	string result = "16";
	EXPECT_EQ(test->stringify(), result);
}

TEST(TruncTest, TruncRight) {
	Op* op1 = new Op(3);
  	Op* op2 = new Op(1);
  	Op* op3 = new Op(5);
  	Sub* sub1 = new Sub(op1, op2);
  	Trunc* t1 = new Trunc(sub1);
  	Mult* test = new Mult(op3, t1);
  	string result = "5 * 2";
	EXPECT_EQ(test->stringify(), result);
}

TEST(TruncTest, TruncateLeft) {
  	Op* op1 = new Op(4);
  	Op* op2 = new Op(1);
  	Op* op3 = new Op(10);
  	Div* div1 = new Div(op1, op2);
  	Trunc* t1 = new Trunc(div1);
  	Add* test = new Add(t1, op3);
  	string result = "4 + 10";
	EXPECT_EQ(test->stringify(), result);
}

TEST(FullTest, Test1) {
	Op* op1 = new Op(1);
	Op* op2 = new Op(2);
	Op* op3 = new Op(3);
	Op* op6 = new Op(6);
	Sub* sub1 = new Sub(op2, op1);
	Paren* p1 = new Paren(sub1);
	Add* add1 = new Add(op6, op3);
	Paren* p2 = new Paren(add1);
	Mult* mult1 = new Mult(p1, p2);
	Trunc* t1 = new Trunc(sub1);
	Sub* test = new Sub(mult1, t1);
	string result = "(2 - 1) * (6 + 3) - 1";
	EXPECT_EQ(test->stringify(), result);
}

TEST(FullTest, Test2) {
	Op* op1 = new Op(1);
	Op* op2 = new Op(2);
	Sub* sub1 = new Sub(op2, op1);
	Trunc* t1 = new Trunc(sub1);
	Paren* test = new Paren(t1);
	string result = "(1)";
	EXPECT_EQ(test->stringify(), result);
}

TEST(FullTest, Test3) {
	Op* op1 = new Op(-1.5);
	Floor* floor1 = new Floor(op1);
	Ceil* ceil1 = new Ceil(floor1);
	Abs* test = new Abs(ceil1);
	EXPECT_EQ(test->evaluate(), 2);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
