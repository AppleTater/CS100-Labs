#include "gtest/gtest.h"
#include "factory.hpp"

TEST(Test, Add) {
	char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "5"; test_val[2] = "+" ; test_val[3] = "3";
	Factory* f = new Factory();
	Base* test = f->parse(test_val, 4);
	string resultS = test->stringify();
	double resultE = test->evaluate();
	EXPECT_EQ("5 + 3", resultS);
	EXPECT_EQ(8, resultE);
}

TEST(Test, Sub) {
	char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "925"; test_val[2] = "-" ; test_val[3] = "87";
	Factory* f = new Factory();
	Base* test = f->parse(test_val, 4);
	string resultS = test->stringify();
	double resultE = test->evaluate();
	EXPECT_EQ("925 - 87", resultS);
	EXPECT_EQ(838, resultE);
}

TEST(Test, AddSub) {
	char* test_val[6]; test_val[0] = "./calculator"; test_val[1] = "1"; test_val[2] = "+" ; test_val[3] = "8"; test_val[4] = "-"; test_val[5] = "3";
	Factory* f = new Factory();
	Base* test = f->parse(test_val, 6);
	string resultS = test->stringify();
	double resultE = test->evaluate();
	EXPECT_EQ("1 + 8 - 3", resultS);
	EXPECT_EQ(6, resultE);
}

TEST(Test, Mult) {
	char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "4"; test_val[2] = "\*" ; test_val[3] = "2";
	Factory* f = new Factory();
	Base* test = f->parse(test_val, 4);
	string resultS = test->stringify();
	double resultE = test->evaluate();
	EXPECT_EQ("4 * 2", resultS);
	EXPECT_EQ(8, resultE);
}

TEST(Test, Div) {
	char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "25"; test_val[2] = "/" ; test_val[3] = "5";
	Factory* f = new Factory();
	Base* test = f->parse(test_val, 4);
	string resultS = test->stringify();
	double resultE = test->evaluate();
	EXPECT_EQ("25 / 5", resultS);
	EXPECT_EQ(5, resultE);
}

TEST(Test, PowZero){
	char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "0"; test_val[2] = "\**" ; test_val[3] = "4";
	Factory* f = new Factory();
	Base* test = f->parse(test_val, 4);
	string resultS = test->stringify();
	double resultE = test->evaluate();
	EXPECT_EQ("0 ** 4", resultS);
	EXPECT_EQ(0, resultE);
}

TEST(Test, Pow){
	char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "3"; test_val[2] = "\**" ; test_val[3] = "2";
	Factory* f = new Factory();
	Base* test = f->parse(test_val, 4);
	string resultS = test->stringify();
	double resultE = test->evaluate();
	EXPECT_EQ("3 ** 2", resultS);
	EXPECT_EQ(9, resultE);
}

TEST(Test, Num) {
	char* test_val[2]; test_val[0] = "./calculator"; test_val[1] = "5";
	Factory* f = new Factory();
	Base* test = f->parse(test_val, 2);
	string resultS = test->stringify();
	double resultE = test->evaluate();
	EXPECT_EQ("5", resultS);
	EXPECT_EQ(5, resultE);
}

TEST(Test, StinkyGarbage){
	char* test_val[2]; test_val[0] = "./calculator"; test_val[1] = "renegaderenegaderenegaderenegade";
	Factory* f = new Factory();
	Base* test = f->parse(test_val, 2);
	ASSERT_TRUE(test == nullptr);
	cout << "Try again, your input is trash smh" << endl;
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
