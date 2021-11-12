#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

void Test1()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);
	SListDestory(&plist);
}

void Test2()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 5);
	SListPrint(plist);
	SListDestory(&plist);
}

void Test3()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 5);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);

	SListPrint(plist);
	SListDestory(&plist);
}

void Test4()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 5);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListDestory(&plist);
}

void Test5()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);
	SLTNode* pos1 = SListFind(plist, 3);
	SLTNode* pos2 = SListFind(plist, 1);
	SListInsertAfter(pos1, 6);
	SListInsertBefore(&plist, pos2, 7);
	SListPrint(plist);
	SListDestory(&plist);
}

void Test6()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);
	SLTNode* pos1 = SListFind(plist, 2);
	SLTNode* pos2 = SListFind(plist, 4);
	SListEraseAfter(pos1);
	SListPrint(plist);
	SListErase(&plist, pos2);
	SListPrint(plist);
	SListDestory(&plist);
}

//int main()
//{
//	//Test1();
//	//Test2();
//	//Test3();
//	//Test4();
//	//Test5();
//	Test6();
//	return 0;
//}

#include"List.h"

void LTest1()
{
	LTNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);
}

void LTest2()
{
	LTNode* plist = ListInit();
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	ListPrint(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);
}

void LTest3()
{
	LTNode* plist = ListInit();

	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);

	LTNode* pos = ListFind(plist, 2);
	LTNode* pos2 = ListFind(plist, 4);
	ListInsert(pos, 6);
	ListPrint(plist);
	ListErase(pos2);
	ListPrint(plist);
	ListDestory(plist);
	plist = NULL;
}

int main()
{
	//LTest1();
	//LTest2();
	LTest3();
	return 0;
}