#include "pch.h"
#include "..//ForwardList/ForwardList.h"

TEST(FListTests, get_and_push_back)
{
	ForwardList<int> list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	ASSERT_EQ(list.get(0), 1);
	ASSERT_EQ(list.get(1), 2);
	ASSERT_EQ(list.get(2), 3);

	ASSERT_THROW(list.get(3), std::out_of_range);
}

TEST(FListTests, clear)
{
	ForwardList<int> list;

	list.push_back(1);

	list.clear();

	ASSERT_THROW(list.get(0), std::out_of_range);
}

TEST(FListTests, insert)
{
	ForwardList<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	list.insert_after(list.first(), 5);
	ASSERT_EQ(list.get(0), 1);
	ASSERT_EQ(list.get(1), 5);
	ASSERT_EQ(list.get(2), 2);
	ASSERT_EQ(list.get(3), 3);

	ASSERT_THROW(list.get(4), std::out_of_range);
}

TEST(FListTests, push_front)
{
	ForwardList<int> list;

	list.push_front(42);
	ASSERT_EQ(list.get(0), 42);

	list.push_front(58);
	ASSERT_EQ(list.get(0), 58);
	ASSERT_EQ(list.get(1), 42);
}

TEST(FListTests, remove)
{
	ForwardList<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	list.remove(2);
	ASSERT_EQ(list.get(0), 1);
	ASSERT_EQ(list.get(1), 3);

	ASSERT_THROW(list.get(3), std::out_of_range);
}

TEST(FListTests, first_last) // у меня на этом тесте программа упала
							 // не знаю в чем может-быть причина, у меня все тесты проходят
							 // Ок, скиньте мне тогда упакованный моим скриптом проект из Visual Studio
{
	ForwardList<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	ASSERT_EQ(list.first()->_value, list.get(0));
	ASSERT_EQ(list.last()->_value, list.get(2));
}

TEST(FListTests, empty)
{
	ForwardList<int> list;
	EXPECT_EQ(list.empty(), true);

	list.push_back(55);
	EXPECT_EQ(list.empty(), false);
}

TEST(FListTests, reverse_1)
{
	ForwardList<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	list.reverse();
	ASSERT_EQ(list.get(0), 3);
	ASSERT_EQ(list.get(1), 2);
	ASSERT_EQ(list.get(2), 1);
}

TEST(FListTests, reverse_2)
{
	ForwardList<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);

	list.reverse();
	ASSERT_EQ(list.get(0), 6);
	ASSERT_EQ(list.get(1), 5);
	ASSERT_EQ(list.get(2), 4);
	ASSERT_EQ(list.get(3), 3);
	ASSERT_EQ(list.get(4), 2);
	ASSERT_EQ(list.get(5), 1);

	ASSERT_THROW(list.get(6), std::out_of_range);
}

TEST(FListTests, size)
{
	ForwardList<int> list;

	ASSERT_EQ(0, list.size());

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);

	ASSERT_EQ(6, list.size());
}

TEST(FListTests, operators)
{
	ForwardList<int> list1;
	list1.push_back(1);
	list1.push_back(2);

	ForwardList<int> list2;
	list2.push_back(1);

	ASSERT_THROW(list1 != list2, std::length_error);

	list2.push_back(3);
	ASSERT_FALSE(list1 == list2);
	ASSERT_TRUE(list1 != list2);

	list2.remove(3);
	list2.push_back(2);
	ASSERT_TRUE(list1 == list2);
	ASSERT_FALSE(list1 != list2);
}