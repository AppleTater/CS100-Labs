#include "c-echo.h"

#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld) {
  char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world";
    EXPECT_EQ("hello world", echo(3,test_val));
}

TEST(EchoTest, EmptyString) {
  char* test_val[1]; test_val[0] = "./c-echo";
    EXPECT_EQ("", echo(1,test_val));
}

TEST(EchoTest, AppleTater) {
   char* test_val[2]; test_val[0] = "./c-echo"; test_val[1] = "@|o|o137@73|2";
    EXPECT_EQ("@|o|o137@73|2", echo(2,test_val));
}

TEST(EchoTest, SummerCS100) {
   char* test_val[4]; test_val[0] = "./c-echo"; test_val[1] = "Summer"; test_val[2] = "CS"; test_val[3] = "100";
    EXPECT_EQ("Summer CS 100", echo(4,test_val));
}

TEST(EchoTest, PerryThePlatypus) {
   char* test_val[7]; test_val[0] = "./c-echo"; test_val[1] = "Agent"; test_val[2] = "P"; test_val[3] = "="; test_val[4] = "Perry"; test_val[5] = "the"; test_val[6] = "Platypus";
    EXPECT_EQ("Agent P = Perry the Platypus", echo(7,test_val));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
