#include "gtest/gtest.h"
#include "expressionstream.h"

class Lab01Fixture : public ::testing::Test {

protected:
    virtual void TearDown() {
        delete stream1;
        delete stream2;
    }

    virtual void SetUp() {
        stream1=new expressionstream("1+2+3");
        stream2=new expressionstream("1   + 2 *4+(2*3)");
        stream3=new expressionstream("-1 +-2");
    }


public:
    expressionstream *stream1;
    expressionstream *stream2;
    expressionstream *stream3;
};




TEST(crashTest , constructorTest) {
    expressionstream stream1 ("1+2+3");
    expressionstream stream2 ("1   + 2 *4+(2*3)");
}


TEST_F(Lab01Fixture, basicTest) {
    EXPECT_EQ("1",stream1->get_next_int());
    EXPECT_EQ("2",stream1->get_next_int());
    EXPECT_EQ("3",stream1->get_next_int());

    EXPECT_EQ("+",stream1->get_next_op());
    EXPECT_EQ("+",stream1->get_next_op());
//todo: Get these tests to pass using the debugger
    EXPECT_EQ("1",stream2->get_next_int());
    EXPECT_EQ("2",stream2->get_next_int());
    EXPECT_EQ("4",stream2->get_next_int());
    EXPECT_EQ("2",stream2->get_next_int());
    EXPECT_EQ("3",stream2->get_next_int());

    EXPECT_EQ("+",stream2->get_next_op());
    EXPECT_EQ("*",stream2->get_next_op());
    EXPECT_EQ("+",stream2->get_next_op());
    EXPECT_EQ("(",stream2->get_next_op());
    EXPECT_EQ("*",stream2->get_next_op());
    EXPECT_EQ(")",stream2->get_next_op());

    EXPECT_EQ("+", stream3->get_next_op());
    EXPECT_EQ("-1", stream3->get_next_int());
    EXPECT_EQ("-2", stream3->get_next_int());
}

TEST_F(Lab01Fixture, isNext) {
    EXPECT_FALSE(stream1->expression_complete());
    stream1->get_next_int();
    stream1->get_next_int();
    stream1->get_next_int();
    EXPECT_FALSE(stream1->expression_complete());
    stream1->get_next_op();
    stream1->get_next_op();
    EXPECT_TRUE(stream1->expression_complete());
}


//todo: create a new test
//step 1: press alt+insert (or right click and select generate)
//step 2: choose test to generate a new test where the cursor is
//step 3: type "Lab01Fixture" in the red box and press tab to go to next auto fill box
//step 4: type name of your test
//step 5: inside the function create your test, use previous test as examples

TEST_F(Lab01Fixture, NotEqualToTwenty) {        //First test to see if first integer of stream4 is not equal to 20.
    expressionstream stream4("1+2*4");

    EXPECT_NE("20",stream4.get_next_int());
}

TEST_F(Lab01Fixture, EqualToZero) {             //Second test to see if first integer of stream5 is equal to 0.
    expressionstream stream5("0+2+23");

    EXPECT_EQ("0", stream5.get_next_int());
}

TEST_F(Lab01Fixture, NotEqualToMinus){          //Third test to determine if the first operator is not a minus.
    EXPECT_NE("-", stream1->get_next_op());
}

TEST_F(Lab01Fixture, Stream1OperatorOrder) {
    EXPECT_EQ("+", stream1->get_next_op());     //Fourth test tests if the first operator is a plus and if the second is not a minus.
    EXPECT_NE("-", stream1->get_next_op());
}

TEST_F(Lab01Fixture, Stream3Integers) {
    EXPECT_EQ("-1", stream3->get_next_int());   //Fifth test to determine if the two integers in stream3 are -1 and -2 in that exact order.
    EXPECT_EQ("-2", stream3->get_next_int());
}
