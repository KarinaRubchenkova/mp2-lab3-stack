#include "pch.h"
#include "../MP2_Lab3_Stack/Stack.h"

TEST(StackTest, ñan_ñreate_empty_stack) {
    Stack<int> st;
    EXPECT_TRUE(st.IsEmpty());
}
TEST(StackTest, can_create_stack_with_given_size) {
    Stack<int> st(12);
    ASSERT_NO_THROW(st);
}
TEST(StackTest, cannot_create_stack_with_zero_size) {
    ASSERT_ANY_THROW(Stack<int> st(0););
}
TEST(StackTest, cannot_create_stack_with_negative_size) {
    ASSERT_ANY_THROW(Stack<int> st(-3););
}
TEST(StackTest, cant_create_too_large_stack)
{
    ASSERT_ANY_THROW(Stack<int> m(MAX_STACK_SIZE + 1));
}
TEST(StackTest, can_copy_stack) {
    Stack<int> st(3);
    st.Push(1);
    st.Push(2);
    st.Push(3);
    Stack<int> st_2(st);
    ASSERT_NO_THROW(st_2);
}
TEST(StackTest, copied_stack_is_equal_to_original) {
    Stack<int> st(3);
    Stack<int> st_2(st);
    EXPECT_TRUE(st  == st_2);
}
TEST(StackTest, can_push_element) {
    Stack<int> st(3);
    ASSERT_NO_THROW(st.Push(2));
}
TEST(StackTest, can_push_multiple_elements) {
    Stack<int> st(3);
    ASSERT_NO_THROW(st.Push(2));
    ASSERT_NO_THROW(st.Push(1));
    ASSERT_NO_THROW(st.Push(4));
}
TEST(StackTest, cannot_push_into_full_stack) {
    Stack<int> st(3);
    st.Push(1);
    st.Push(2);
    st.Push(3);
    ASSERT_ANY_THROW(st.Push(5));
}
TEST(StackTest, can_pop_element) {
    Stack<int> st(3);
    st.Push(1);
    st.Push(2);
    st.Push(3);
    ASSERT_NO_THROW(st.Pop());
}
TEST(StackTest, pop_returns_last_pushed_element) {
    Stack<int> st(3);
    st.Push(1);
    st.Push(2);
    st.Push(3);
    EXPECT_EQ(3,st.Pop());
}
TEST(StackTest, cannot_pop_from_empty_stack) {
    Stack<int> st(3);
    ASSERT_ANY_THROW(st.Pop());
}
TEST(StackTest, can_get_top_element) {
    Stack<int> st(3);
    st.Push(1);
    st.Push(2);
    st.Push(3);
    EXPECT_EQ(3, st.Top());
}
TEST(StackTest, top_does_not_modify_stack) {
    Stack<int> st(3);
    st.Push(1);
    st.Push(2);
    st.Push(3);
    Stack<int> st_2(st);

    EXPECT_EQ(3, st.Top());
    EXPECT_EQ(st, st_2);
}
TEST(StackTest, cannot_get_top_from_empty_stack) {
    Stack<int> st(3);
    ASSERT_ANY_THROW(st.Top());
}
TEST(StackTest, new_stack_is_empty) {
    Stack<int> st(3);
    ASSERT_TRUE(st.IsEmpty());
}
TEST(StackTest, stack_with_elements_is_not_empty) {
    Stack<int> st(3);
    st.Push(1);
    st.Push(2);
    st.Push(3);
    ASSERT_FALSE(st.IsEmpty());
}
TEST(StackTest, stack_is_full_after_filling) {
    Stack<int> st(3);
    st.Push(1);
    st.Push(2);
    st.Push(3);
    ASSERT_TRUE(st.IsFull());
}
TEST(StackTest, stack_is_not_full_before_filling) {
    Stack<int> st(3);
    ASSERT_FALSE(st.IsFull());
}
TEST(StackTest, cleared_stack_is_empty) {
    Stack<int> st(3);
    st.Push(1);
    st.Push(2);
    st.Push(3);
    st.Clear_Stack();
    ASSERT_TRUE(st.IsEmpty());
}
TEST(StackTest, can_copy_assign_stack) {
    Stack<int> st(3);
    Stack<int> st_2(2);
    st.Push(1);
    st.Push(2);
    st.Push(3);
    st_2 = st;
    ASSERT_NO_THROW(st_2 = st);
    EXPECT_EQ(st, st_2);
}
TEST(StackTest, copy_assignment_preserves_elements) {

}
TEST(StackTest, can_assign_stack_to_itself) {
    Stack<int> st(3);
    st.Push(1);
    st.Push(2);
    st.Push(3);
    ASSERT_NO_THROW(st = st);
}
TEST(StackTest, stack_is_equal_to_itself) {
    Stack<int> st(3);
    st.Push(1);
    st.Push(2);
    st.Push(3);
    ASSERT_TRUE(st == st);
}
TEST(StackTest, equal_stacks_are_equal) {
    Stack<int> st(3);
    Stack<int> st_2(3);
    st.Push(1);
    st.Push(2);
    st.Push(3);
    st_2 = st;
    ASSERT_TRUE(st == st_2);
}
TEST(StackTest, different_stacks_are_not_equal) {
    Stack<int> st(3);
    Stack<int> st_2(3);
    st.Push(1);
    st.Push(2);
    st.Push(3);
    st_2.Push(4);
    st_2.Push(5);
    st_2.Push(6);
    ASSERT_FALSE(st == st_2);
}
TEST(StackTest, stacks_with_different_sizes_are_not_equal) {
    Stack<int> st(3);
    Stack<int> st_2(4);
    ASSERT_TRUE(st != st_2);
}
TEST(StackTest, stacks_with_different_elements_are_not_equal) {
    Stack<int> st(3);
    Stack<int> st_2(3);
    st.Push(1);
    st.Push(2);
    st.Push(3);
    st_2.Push(4);
    st_2.Push(5);
    st_2.Push(6);
    ASSERT_TRUE(st != st_2);
}


