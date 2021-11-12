#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;

typedef struct QueneNode
{
	struct QueneNode* next;
	QDataType data;
}QNode;

typedef struct Quene
{
	QNode* front;
	QNode* tail;
}Quene;

void QueneInit(Quene* pq);

bool QueneEmpty(Quene* pq);

void QuenePush(Quene* pq, QDataType x);

void QuenePop(Quene* pq);

QDataType QueneFront(Quene* pq);

QDataType QueneBack(Quene* pq);

int QueneSize(Quene* pq);

void QueneDestory(Quene* pq);
