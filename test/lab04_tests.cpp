#include "gtest/gtest.h"
#include "fifo.h"
#include "lifo.h"
#include "calculator.h"

class Lab04Fixture : public ::testing::Test {

protected:
    virtual void SetUp() {

    }

    virtual void TearDown() {

    }

public:
};

TEST(calculator, addTest){
    std::string A ="50+80";
    lab4::calculator Add(A);
    EXPECT_EQ(130, Add.calculate());
}
TEST(calculator, hello){
    std::string B = "5*(3-2)";
    lab4::calculator calc(B);
    EXPECT_EQ(5, calc.calculate());
}
TEST(calculator, hellw){
    std::string C = "(6-2)*5";
    lab4::calculator calc(C);
    EXPECT_EQ(20, calc.calculate());
}
TEST(calculator,divisionTest){
    std::string D ="8/2";
    lab4::calculator div(D);
    EXPECT_EQ(4,div.calculate());
}
TEST(calculator, multTest){
    std::string E = "8*6";
    lab4::calculator mult(E);
    EXPECT_EQ(48, mult.calculate());
}
TEST(calculator, quiz){
    std::string F = "2-(3*4/6)+1";
    lab4::calculator tues(F);
    EXPECT_EQ(1,tues.calculate());
}