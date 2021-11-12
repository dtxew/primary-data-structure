#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

LTNode* ListInit()
{
	LTNode* head = malloc(sizeof(LTNode));
	if (!head)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	head->next = head;
	head->prev = head;
	return head;
}

LTNode* BuyListNode(LTDataType x)
{
	LTNode* newnode = malloc(sizeof(LTNode));
	if (!newnode)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}

void ListPrint(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<->", cur->data);
		cur = cur->next;
	}
	printf("end\n");
}

void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = BuyListNode(x);
	LTNode* tail = phead->prev;

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;


}

void ListPopBack(LTNode* phead)
{
	assert(phead && phead->next != phead);

	LTNode* tail = phead->prev;
	tail->prev->next = phead;
	phead->prev = tail->prev;
	free(tail);
	tail = NULL;

}

void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* newnode = BuyListNode(x);

	newnode->next = phead->next;
	newnode->prev = phead;
	phead->next->prev = newnode;
	phead->next = newnode;
}

void ListPopFront(LTNode* phead)
{
	assert(phead && phead->next != phead);
	LTNode* head = phead->next;

	head->next->prev = phead;
	phead->next = head->next;

	free(head);

	head = NULL;
}

LTNode* ListFind(LTNode* phead,LTDataType x)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);

	LTNode* newnode = BuyListNode(x);
	LTNode* prevPos = pos->prev;
	prevPos->next = newnode;
	newnode->next = pos;
	pos->prev = newnode;
	newnode->prev = prevPos;
}

void ListErase(LTNode* pos)
{
	assert(pos);

	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}

void ListDestory(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	LTNode* next = cur->next;
	while (cur != phead)
	{
		free(cur);
		cur = next;
		if(next != phead)
			next = cur->next;
	}
	free(phead);
	phead = NULL;
}