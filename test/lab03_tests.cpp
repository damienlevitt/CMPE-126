#include "gtest/gtest.h"
#include "fifo.h"
#include "lifo.h"

class Lab03Fixture : public ::testing::Test {

protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }

public:
};


TEST(fifo,constructorTest){
    lab3::fifo obj1;
    EXPECT_EQ(true,obj1.is_empty());
    EXPECT_EQ(0,obj1.size());
}

TEST(fifo,enqueueTest){
    lab3::fifo obj2;
    EXPECT_NO_THROW(obj2.enqueue("String1"));
    EXPECT_NO_THROW(obj2.enqueue("String2"));
    EXPECT_NO_THROW(obj2.enqueue("String3"));
    EXPECT_NO_THROW(obj2.enqueue("String4"));
}

TEST(fifo,dequeueTest){
    lab3::fifo obj3;
    obj3.enqueue("String1");
    obj3.enqueue("String2");
    EXPECT_NO_THROW(obj3.dequeue());
    EXPECT_NO_THROW(obj3.dequeue());
    EXPECT_ANY_THROW(obj3.dequeue());
    //Throws exception if trying to remove from empty queue
}

TEST(fifo,readTest){
    lab3::fifo obj4;
    obj4.enqueue("String1");
    obj4.enqueue("String2");
    EXPECT_EQ("String1",obj4.top());
    obj4.dequeue();
    EXPECT_EQ("String2",obj4.top());
    EXPECT_NO_THROW(obj4.dequeue());
    EXPECT_ANY_THROW(obj4.top());
    //Throws exception if trying to read from queue with no data
}

TEST(fifo,copyConstructor){
    lab3::fifo obj5;
    obj5.enqueue("String1");
    obj5.enqueue("String2");
    lab3::fifo* obj6 = new lab3::fifo(obj5);
    EXPECT_EQ("String1",obj6->top());
    obj6->dequeue();
    EXPECT_EQ("String2",obj6->top());
    delete obj6;
}

TEST(fifo,stringConstructor){
    lab3::fifo obj7("Test String");
    EXPECT_EQ("Test String",obj7.top());
}

TEST(fifo,assignmentTest){
    lab3::fifo obj8;
    lab3::fifo obj9;

    obj8.enqueue("String1");
    obj8.enqueue("String2");
    obj9.enqueue("Test1");
    obj9.enqueue("Test2");

    EXPECT_EQ("String1",obj8.top());
    obj8.dequeue();
    EXPECT_EQ("String2",obj8.top());

    obj8 = obj9;
    EXPECT_EQ("Test1",obj8.top());
    obj8.dequeue();
    EXPECT_EQ("Test2",obj8.top());
}



//==========LIFO Tests==========//

TEST(lifo,constructorTest) {
    lab3::lifo obj1;
    EXPECT_EQ(true,obj1.is_empty());
    EXPECT_EQ(0,obj1.size());
}

TEST(lifo,pushTest){
    lab3::lifo obj2;
    EXPECT_NO_THROW(obj2.push("String 1"));
    obj2.push("String 2");
    EXPECT_EQ("String 2",obj2.top());
}

TEST(lifo,popTest) {
    lab3::lifo obj3;
    obj3.push("Test 1");
    obj3.push("String 2");
    EXPECT_NO_THROW(obj3.pop());
    EXPECT_EQ("Test 1",obj3.top());
    EXPECT_NO_THROW(obj3.pop());
    EXPECT_ANY_THROW(obj3.pop());
    //Throws exception if trying to remove from empty stack
}

TEST(lifo,readTest) {
    lab3::lifo obj4;
    obj4.push("String 1");
    obj4.push("Test 2");
    obj4.push("Popcorn");
    EXPECT_EQ("Popcorn",obj4.top());
    obj4.pop();
    EXPECT_EQ("Test 2",obj4.top());
    EXPECT_NO_THROW(obj4.pop());
    EXPECT_EQ("String 1",obj4.top());
    EXPECT_NO_THROW(obj4.pop());
    EXPECT_ANY_THROW(obj4.top());
    //If trying to read while empty, throws exception
}

TEST(lifo,copyConstructor) {
    lab3::lifo obj5;
    obj5.push("STR 1");
    obj5.push("STR 2");
    EXPECT_NO_THROW(lab3::lifo objTest(obj5));
    lab3::lifo* obj6 = new lab3::lifo(obj5);
    EXPECT_EQ("STR 2",obj6->top());
    EXPECT_NO_THROW(delete obj6);
}

TEST(lifo,assignmentTest){
    lab3::lifo obj7,obj8;
    obj7.push("Data 1");
    obj7.push("Data 2");
    EXPECT_NO_THROW(obj8 = obj7);
    EXPECT_EQ("Data 2",obj8.top());
    obj8.pop();
    EXPECT_EQ("Data 2",obj7.top());
    EXPECT_EQ("Data 1",obj8.top());
}