#define _CRT_SECURE_NO_WARNINGS 1

#include"heap.h"
#include<time.h>

void PrintTopK(int* a, int n, int k)
{
	// 1. 建堆--用a中前k个元素建堆

	// 2. 将剩余n-k个元素依次与堆顶元素交换，不满则则替换
	HP hp;
	HeapInit(&hp);

	int i = 0;
	for (i = 0; i < k; i++)
	{
		HeapPush(&hp, a[i]);
	}

	for (i = k; i < n; i++)
	{
		if (a[i] > HeapTop(&hp))
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}

	HeapPrint(&hp);
	HeapDestory(&hp);
}
void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	PrintTopK(a, n, 10);
}
void HPTest()
{
	HP hp;
	HeapInit(&hp);
	HeapPush(&hp, 11);
	HeapPush(&hp, 22);
	HeapPush(&hp, 33);
	HeapPush(&hp, 355);
	HeapPush(&hp, 234324);
	HeapPush(&hp, 532);
	HeapPush(&hp, 1);
	HeapPush(&hp, 6);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapDestory(&hp);
}

void TestHeapSort()
{
	int a[] = { 324,333,22,4,565,65,3,5666,543,54,4,6,75,45,55,5,50 };
	int size = sizeof(a) / sizeof(a[0]);
	HeapSort(a, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
}

//int main()
//{
//	//HPTest();
//	//TestTopk();
//	TestHeapSort();
//	return 0;
//}