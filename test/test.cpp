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

TEST(set, intConstructor)
{
	set<int> testSet;
	ASSERT_EQ(testSet.find(3), 0);
}

TEST(set, findTest)
{
	set<int> testSet;
	testSet.insert(200);
	testSet.insert(4);

	EXPECT_TRUE(testSet.find(200));
	EXPECT_TRUE(testSet.find(4));
	EXPECT_TRUE(!testSet.find(1));
}

TEST(set, insertTest)
{
	set<int> testSet;
	testSet.insert(3);
	testSet.insert(1);
	testSet.insert(6);

	ASSERT_EQ(testSet.find(3), 1);
	ASSERT_EQ(testSet.find(2), 0);
}

TEST(set, deleteTest)
{
	set<int> testSet;
	testSet.insert(3);
	testSet.insert(-1);
	testSet.insert(-3);
	testSet.insert(8);
	testSet.insert(2);
	testSet.insert(7);

	testSet.erase(8);
	testSet.erase(-1);

	EXPECT_TRUE(testSet.find(2) && testSet.find(3) && testSet.find(-3) && testSet.find(7) && !testSet.find(-1) && !testSet.find(8));
}