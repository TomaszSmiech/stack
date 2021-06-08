#include<iostream>
#include<gtest/gtest.h>
#include "../src/stack.h"


TEST(StackTests,n1){
     stack<int> st;
     st.push_back(2);
     st.push_back(3);
     st.push_back(4);
     st.push_back(10);
	 ASSERT_EQ(10,st.pop_back());
}

TEST(StackTests,n2){
     stack<int> st;
     st.push_back(2);
     st.push_back(3);
     st.push_back(4);
     st.push_back(10);
    st.pop_back();
	ASSERT_EQ(4,st.pop_back());

}
TEST(StackTests,n3){
    stack<int> st;
    st.push_back(2);
    st.push_back(3);
    st.push_back(4);
    st.push_back(10);
    st.pop_back();
    st.pop_back();
    st.pop_back();

	ASSERT_EQ(2,st.pop_back());
	EXPECT_EQ(0,st.size());
}


TEST(StackTests,n4){
    stack<int> st;
    st.push_back(2);
    st.push_back(3);
    st.push_back(4);
    st.push_back(10);
    st.clear();
	EXPECT_EQ(0,st.size());
}

TEST(StackTests,n5){
    stack<int> st;
    EXPECT_THROW(st.pop_back(), std::runtime_error);
}

TEST(StackTests,n6){
    stack<int> st;
	EXPECT_TRUE(st.empty());
}

TEST(StackTests,n7){
    stack<int> st;
    st.push_back(102);
	EXPECT_FALSE(st.empty());
}