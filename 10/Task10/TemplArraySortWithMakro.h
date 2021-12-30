#pragma once
#include "pch.h"
#define TEMPLATE_SORT(Type) \
void Sort_##Type(Type *arr, size_t size){ \
	for(int i = 1; i < size; i++){ \
		Type def = arr[i]; \
		size_t j = i; \
		while(j>0 & (arr[j-1])<def){ \
			arr[j] = arr[j-1]; \
			j--; \
		} \
		arr[j] = def; \
	} \
}
