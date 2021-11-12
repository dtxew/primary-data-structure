#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void Swap(HPDataType* px, HPDataType* py);

void HeapInit(HP* hp);

void HeapDestory(HP* hp);

void AdjustUp(HPDataType* a, int size, int child);

void HeapPrint(HP* hp);

void HeapPush(HP* hp, HPDataType x);

void AdjustDown(HPDataType* a, int size, int parent);

void HeapPop(HP* hp);

int HeapSize(HP* hp);

bool HeapEmpty(HP* hp);

HPDataType HeapTop(HP* hp);

void HeapSort(int* a, int n);
