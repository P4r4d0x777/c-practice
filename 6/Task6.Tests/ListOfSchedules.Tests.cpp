#include "pch.h";
#include "..//Task6/ListOfSchedules.h"

TEST(InputList, ListOfSchedules)
{
	int count = 0;
	Schedule* List = ListOfSchedules("data_with_one_schedule.json", count);
	ASSERT_EQ(1, count);
	ASSERT_STREQ(L"Petrov", List[0].Name);
	ASSERT_STREQ(L"Math", List[0].Subject);
	bool arr1[] = { true, true, true,true,true, false };
	for (int i = 0; i < 6; ++i)
		ASSERT_EQ(arr1[i], List[0].Days[i]);
	delete[] List;
}
TEST(OutputList, OutputListToFile)
{
	int count = 0;
	Schedule* List = ListOfSchedules("data_with_ten_schedules.json", count);
	OutputListToFile("Schedules.txt", List, count);
}
TEST(SortingtList, SortingOutputListToFile)
{
	int count = 0;
	Schedule* List = ListOfSchedules("data_with_ten_schedules.json", count);
	Sorting(List, count);
	OutputListToFile("SortSchedules.txt", List, count);
}
TEST(SearchingList, SearchingListToFile)
{
	int count = 0;
	Schedule* List = ListOfSchedules("data_with_ten_schedules.json", count);
	const bool days[6] = { true,true,true,true,true,true };
	List = Searching(List, count, days);
	OutputListToFile("SearchingSchedules.txt", List, count);
}

