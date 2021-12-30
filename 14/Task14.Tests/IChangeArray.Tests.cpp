#include "pch.h"
#include "../Task14/IChangeArray.h"

TEST(Tests, TestBubble_decrease)
{
	IChangeArray* a;
	int* example = new int[5];
	example[0] = 27;
	example[1] = 4;
	example[2] = 13;
	example[3] = 2;
	example[4] = 16;
	Bubble<int> arr(example, 5);
	for(UINT i = 0; i < 5; i++)
		ASSERT_EQ(arr[i], example[i]);
	arr.Sort();
	int* res = new int[5];
	res[0] = 27;
	res[1] = 16;
	res[2] = 13;
	res[3] = 4;
	res[4] = 2;
	for (UINT i = 0; i < 5; i++)
		ASSERT_EQ(arr[i], res[i]);
	delete[] res, example;
}
TEST(Tests, TestChoice_increase)
{
	IChangeArray* a;
	int* example = new int[5];
	example[0] = 27;
	example[1] = 4;
	example[2] = 13;
	example[3] = 2;
	example[4] = 16;
	Choice<int> arr(example, 5);
	for (UINT i = 0; i < 5; i++)
		ASSERT_EQ(arr[i], example[i]);
	arr.Sort();
	int* res = new int[5];
	res[0] = 2;
	res[1] = 4;
	res[2] = 13;
	res[3] = 16;
	res[4] = 27;
	for (UINT i = 0; i < 5; i++)
		ASSERT_EQ(arr[i], res[i]);
	delete[] res, example;
}

TEST(Tests, TestOfLoad)
{
	int* example = new int[5];
	example[0] = 27;
	example[1] = 4;
	example[2] = 13;
	example[3] = 2;
	example[4] = 16;
	RegisterLoaders<int>();

	IChangeArray* objects[] = { new Bubble<int>(example, 5), new Choice<int>(example, 5), new Bubble<int>(example, 5), new Choice<int>(example,5)};
	objects[0]->Sort();
	objects[1]->Sort();
	objects[3]->Sort();
	Save("AbstractFactory.txt", objects, 4);

	std::vector<IChangeArray*> loadedObjects = Load("AbstractFactory.txt");
	size_t size = loadedObjects.size();

	ASSERT_EQ(4, size); // И всё? Разве достаточно проверить только количество?

	for(int i =0;i < 4; ++i )
		ASSERT_EQ(5,((Bubble<int>*)loadedObjects[i])->length());
	// Все равно спорный момент. А вдруг массив считался неверно? А вы только длины проверили. А на самом деле там 5 нулей?

	delete[] example;
}