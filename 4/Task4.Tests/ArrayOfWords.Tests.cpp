#include "pch.h"
#include "../Task4/ArrayOfWords.h"

TEST(Task4Tests, CountOfWords)
{
	const char str1[] = "abc ;   14a;; 242af;; ab;c  abc  abc ;;; abc";
	const char word[] = "abc";
	// так, стоп. Функция должна вызываться как-то типа Count("Это исходная строка где будут слово, слово2, слово", "слово"). В данном примере она должна вернуть 2
	ASSERT_EQ(Count(str1,word), 4);
}