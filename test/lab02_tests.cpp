#include "gtest/gtest.h"
#include "stringVector.h"


TEST(stringVector, constructorTest) {
    lab2::stringVector hw0;
    EXPECT_TRUE(hw0.empty());
    EXPECT_EQ(0, hw0.size());
    EXPECT_EQ(0, hw0.capacity());
}

TEST(stringVector, overloadBracket) {
    lab2::stringVector hw1;
    hw1.append("Hello");
    EXPECT_EQ("Hello", hw1[0]);
    hw1[0] = "Changed";
    EXPECT_EQ("Changed", hw1[0]);
}

TEST(stringVector, variableAllocation) {
    lab2::stringVector hw2;
    hw2.append("Test 1");
    hw2.append("Test 2");
    EXPECT_EQ(2, hw2.size());
    EXPECT_EQ(2, hw2.capacity());
    EXPECT_EQ("Test 1", hw2[0]);
    EXPECT_EQ("Test 2", hw2[1]);
}

TEST(stringVector, pointerTest) {
    lab2::stringVector *hw3 = new lab2::stringVector;
    EXPECT_TRUE(hw3->empty());
    delete hw3;
}

TEST(stringVector, reserveConcatination) {
    lab2::stringVector *hw4 = new lab2::stringVector;
    for (int i = 0; i < 10; i++) {
        hw4->append(std::to_string(i));
    }
    EXPECT_EQ(10, hw4->size());
    EXPECT_EQ(16, hw4->capacity());
    EXPECT_EQ("9", (*hw4)[9]);

    hw4->reserve(5);
    EXPECT_EQ(5, hw4->size());
    EXPECT_EQ(5, hw4->capacity());
    EXPECT_EQ("4", (*hw4)[4]);

    hw4->reserve(6);
    EXPECT_EQ(5, hw4->size());
    EXPECT_EQ(6, hw4->capacity());
    EXPECT_EQ("", (*hw4)[5]);
    delete hw4;
}

TEST(stringVector, expectionTesting) {
    lab2::stringVector hw5;
    hw5.reserve(2);
    hw5.append("Test String");
    EXPECT_EQ("Test String", hw5[0]);
    EXPECT_EQ("", hw5[1]);
    EXPECT_THROW(hw5[2], int);

    EXPECT_NO_THROW(hw5.swap(0, 1));
    EXPECT_EQ("", hw5[0]);
    EXPECT_EQ("Test String", hw5[1]);
    EXPECT_THROW(hw5.swap(0, 2), int);
}

TEST(stringVector, overloadAssignment) {
    lab2::stringVector hw6;
    for (int i = 0; i < 6; i++) {
        hw6.append(std::to_string(i));
    }
    EXPECT_EQ(6, hw6.size());
    EXPECT_EQ(8, hw6.capacity());
    EXPECT_EQ("5", hw6[5]);

    lab2::stringVector *hw7 = new lab2::stringVector;
    *hw7 = hw6;
    EXPECT_EQ(6, hw7->size());
    EXPECT_EQ(8, hw7->capacity());
    EXPECT_EQ("5", (*hw7)[5]);
}

        
TEST(stringVector, sorting) {
    lab2::stringVector hw8;
    hw8.append("Part 3");
    hw8.append("Part 1");
    hw8.append("Part 4");
    hw8.append("Part 2");
    hw8.append("Part Test");
    hw8.append("Test 1");

    EXPECT_NO_THROW(hw8.sort());
    EXPECT_EQ("Part 1", hw8[0]);
    EXPECT_EQ("Part 2", hw8[1]);
    EXPECT_EQ("Part 3", hw8[2]);
    EXPECT_EQ("Part 4", hw8[3]);
    EXPECT_EQ("Part Test", hw8[4]);
    EXPECT_EQ("Test 1", hw8[5]);
}
