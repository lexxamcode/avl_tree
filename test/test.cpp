#include "../headers/set.h"
#include <gtest/gtest.h>

TEST(node, nodeIntConstructor)
{
	node<int> testNode;
	ASSERT_EQ(testNode.data(), 0);
	ASSERT_EQ(testNode.left(), nullptr);
	ASSERT_EQ(testNode.right(), nullptr);
}
TEST(node, copyConstructor)
{
	node<int> testNode(2);
	node<int> copyNode(testNode);

	ASSERT_EQ(copyNode.data(), 2);
	ASSERT_EQ(copyNode.left(), nullptr);
	ASSERT_EQ(copyNode.right(), nullptr);
}

TEST(node, copyOperator)
{
	node<int> testNode(2);
	node<int> copyNode = testNode;

	ASSERT_EQ(copyNode.data(), 2);
	ASSERT_EQ(copyNode.left(), nullptr);
	ASSERT_EQ(copyNode.right(), nullptr);
}