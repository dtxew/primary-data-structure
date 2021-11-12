#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListPrint(SL* ps)
{
	if (!ps->size)
	{
		printf("NULL");
		exit(-1);
	}
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newcapacity);
		if (!tmp)
		{
			printf("%s\n", strerror(errno));
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;

	}
}

void SeqListPushBack(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
void SeqListPushFront(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}
void SeqListPopBack(SL* ps)
{
	assert(ps->size);
	ps->size--;
}
void SeqListPopFront(SL* ps)
{
	assert(ps->size);
	int start = 0;
	while (start < ps->size - 1)
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	ps->size--;
}

int SeqListFind(SL* ps, SLDataType x)
{
	assert(ps->a);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i + 1;
		}
	}
	return -1;
}

void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	SeqListCheckCapacity(ps);
	if (pos <= 1)
	{
		SeqListPushFront(ps, x);
	}
	else if (pos >= ps->size)
	{
		SeqListPushBack(ps, x);
	}
	else
	{
		int end = ps->size - 1;
		while (end >= pos - 1)
		{
			ps->a[end + 1] = ps->a[end];
			end--;
		}
		ps->a[pos - 1] = x;
		ps->size++;
	}
}

void SeqListErase(SL* ps, int pos)
{
	assert(ps->size);
	if (pos == 1)
	{
		SeqListPopFront(ps);
	}
	else if (pos == ps->size)
	{
		SeqListPopBack(ps);
	}
	else
	{
		int cur = pos - 1;
		while (cur < ps->size)
		{
			ps->a[cur] = ps->a[cur + 1];
			cur++;
		}
		ps->size--;
	}
}


