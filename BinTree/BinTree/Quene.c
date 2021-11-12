#define _CRT_SECURE_NO_WARNINGS 1
#include"Quene.h"

void QueneInit(Quene* pq)
{
	assert(pq);

	pq->front = NULL;
	pq->tail = NULL;
}

bool QueneEmpty(Quene* pq)
{
	assert(pq);
	return pq->front == NULL;
}

void QuenePush(Quene* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (!newnode)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;

	if (QueneEmpty(pq))
	{
		pq->front = newnode;
		pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;

	}
	
}

void QuenePop(Quene* pq)
{
	assert(pq);
	assert(!QueneEmpty(pq));
	QNode* newfront = pq->front->next;
	free(pq->front);
	pq->front = newfront;
	if (!newfront)
	{
		pq->tail = NULL;
	}
}

QDataType QueneFront(Quene* pq)
{
	assert(pq);
	assert(!QueneEmpty(pq));
	return pq->front->data;
}

QDataType QueneBack(Quene* pq)
{
	assert(pq);
	assert(!QueneEmpty(pq));
	return pq->tail->data;
}

int QueneSize(Quene* pq)
{
	assert(pq);
	assert(!QueneEmpty(pq));
	int cnt = 0;
	QNode* cur = pq->front;
	while (cur)
	{
		cur = cur->next;
		cnt++;
	}
	return cnt;
}

void QueneDestory(Quene* pq)
{
	assert(pq);
	QNode* cur = pq->front;
	

	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
		
	}
	pq->front = pq->tail = NULL;

}