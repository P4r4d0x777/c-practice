#include "pch.h"
#include "../Task4/ArrayOfWordsEqual.h"

TEST(Task4Tests, ArrayOfWords_4)
{
	const char str1[] = "      01   0111 111 11    000";
	const char str2[] = "0111"; // Зачем тут память выделять, если ниже все равно присваивание
	char* arrayOfWords = ArrayOfWordsEqual(str1);
	EXPECT_STREQ(str2, arrayOfWords);
	// так, не понял. Это какой пункт задания? Если первый то там написано "найти и возвратить самую длинную группу цифр". Что вы тут в цикле проверяете?
	// ну в задании я уже написал, что у вас будет возвращаться NULL. У меня один вопрос - как вы сдаете? Совсем не проверяете?
}
TEST(Task4Tests, ArrayOfWords_6)
{
	const char str1[] = "      01   0111 111 11    000001";
	const char str2[] = "000001";
	char* arrayOfWords = ArrayOfWordsEqual(str1);
	EXPECT_STREQ(str2, arrayOfWords);
}