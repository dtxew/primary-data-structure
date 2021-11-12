#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

LTNode* ListInit();

LTNode* BuyListNode(LTDataType x);

void ListPrint(LTNode* phead);

void ListPushBack(LTNode* phead, LTDataType x);

void ListPopBack(LTNode* phead);

void ListPushFront(LTNode* phead, LTDataType x);

void ListPopFront(LTNode* phead);

LTNode* ListFind(LTNode* phead,LTDataType x);

void ListInsert(LTNode* pos, LTDataType x);

void ListErase(LTNode* pos);

void ListDestory(LTNode* phead);
