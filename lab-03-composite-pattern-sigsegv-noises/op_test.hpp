#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, OpEvaluateZero){
    Op* test = new Op(0);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, OpStringZero){
    Op* test = new Op(0);
    std::string zero = "0";
    EXPECT_EQ(test->stringify(), zero);
}

TEST(OpTest, OpEvaluateNegNine){
    Op* test = new Op(-9);
    EXPECT_EQ(test->evaluate(), -9);
}

TEST(OpTest, OPStringNegHun){
    Op* test = new Op(-100);
    std::string neg_hun = "-100";
    EXPECT_EQ(test->stringify(), neg_hun);
}

TEST(OpTest, OpStringNineTwo) {
    Op* test = new Op(9.2);
    std::string nine = "9.2";
    EXPECT_EQ(test->stringify(), nine);
}


#endif //__OP_TEST_HPP__
