#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
#include"Quene.h"

void STTest()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	StackDestory(&st);
}

void QTest()
{
	Quene q;
	QueneInit(&q);
	QuenePush(&q, 1);
	QuenePush(&q, 2);
	QuenePush(&q, 3);
	QuenePush(&q, 4);
	printf("%d ", QueneFront(&q));
	QuenePop(&q);
	printf("%d ", QueneFront(&q));
	QuenePop(&q);
	printf("%d ", QueneFront(&q));
	QuenePop(&q);
	printf("%d ", QueneFront(&q));
	QuenePop(&q);
	QueneDestory(&q);
}

int main()
{
	//STTest();
	QTest();
	return 0;
}