#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

//void HeapSort(int* a, int n)
//{
//	assert(a);
//	//����method1
//	/*for (int i = 1; i < n; i++)
//	{
//		AdjustUp(a, i + 1, i);
//	}*/
//	//����method2
//
//	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
//	{
//		AdjustDown(a, n, i);
//	}
//
//	for (int i = n - 1; i >= 1; i--)
//	{
//		Swap(&a[0], &a[i]);
//		AdjustDown(a, i, 0);
//	}
//
//}

void HeapSort(int* a, int n)
{
	assert(a);
	int i = 0;
	for (i = 1; i < n; i++)
	{
		AdjustUp(a, i + 1, i);
	}

	for (i = n - 1; i >= 0; i--)
	{
		Swap(&a[0], &a[i]);
		AdjustDown(a, i, 0);
	}
}