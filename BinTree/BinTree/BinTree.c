#define _CRT_SECURE_NO_WARNINGS 1


#include"Quene.h"

typedef int BTDataType;

typedef struct BinTreeNode
{
	struct BinTreeNode* left;
	struct BinTreeNode* right;
	BTDataType data;
}BTNode;

BTNode* createBinTree()
{
	BTNode* n1 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n2 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n3 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n4 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n5 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n6 = (BTNode*)malloc(sizeof(BTNode));
	BTNode* n7 = (BTNode*)malloc(sizeof(BTNode));
	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;
	n5->data = 5;
	n6->data = 6;
	n7->data = 7;

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = NULL;
	n4->left = n7;
	n4->right = NULL;
	n5->left = NULL;
	n5->right = NULL;
	n6->left = NULL;
	n6->right = NULL;
	n7->left = NULL;
	n7->right = NULL;

	return n1;
}

void PrevOrder(BTNode* root)
{
	if (!root)
	{
		printf("NULL");
		return;
	}

	printf("%d ", root->data);

	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (!root)
	{
		printf("NULL");
		return;
	}

	

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

void PostOrder(BTNode* root)
{
	if (!root)
	{
		printf("NULL");
		return;
	}



	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

int BinTreeSize(BTNode* root)
{
	return !root ? 0 : 1 + BinTreeSize(root->left) + BinTreeSize(root->right);
}

int BinTreeLeafSize(BTNode* root)
{
	if (!root)
		return 0;
	//else if (root->left == NULL && root->right == NULL)
	//	return 1;
	//else
	//	return BinTreeLeafSize(root->left) + BinTreeLeafSize(root->right);
	return root->left == NULL && root->right == NULL ? 1 : BinTreeLeafSize(root->left) + BinTreeLeafSize(root->right);
}

int BinTreeLevelKSize(BTNode* root, int k)
{
	//返回第K层结点个数
	assert(k >= 0);
	if (!root)
		return 0;
	if (k == 1)
		return 1;
	return BinTreeLevelKSize(root->left, k - 1) + BinTreeLevelKSize(root->right, k - 1);
	
}

int BinTreeDepth(BTNode* root)
{
	if (!root)
		return 0;
	//函数调用频繁
	//return BinTreeDepth(root->left) > BinTreeDepth(root->right) ? 1 + BinTreeDepth(root->left) : 1 + BinTreeDepth(root->right);

	//用变量保存

	int leftDepth = BinTreeDepth(root->left);
	int rightDepth = BinTreeDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

BTNode* BinTreeFind(BTNode* root, BTDataType x)
{
	if (!root)
		return NULL;
	if (root->data == x)
		return root;
	BTNode* Left = BinTreeFind(root->left, x);
	if (Left)
		return Left;
	BTNode* Right = BinTreeFind(root->right, x);
	if (Right)
		return Right;
	return NULL;
}


void LevelOrder(BTNode* root)
{
	if (!root)
		return;
	Quene q;
	QueneInit(&q);

	QuenePush(&q, root);

	while (!QueneEmpty(&q))
	{
		BTNode* front = QueneFront(&q);
		QuenePop(&q);
		printf("%d ", front->data);
		
		if (front->left)
			QuenePush(&q, front->left);
		if (front->right)
			QuenePush(&q, front->right);

	}
	QueneDestory(&q);
}



bool BinTreeComplete(BTNode* root)
{
	if (!root)
		return true;

	Quene q;
	QueneInit(&q);

	QuenePush(&q, root);

	while (!QueneEmpty(&q))
	{
		BTNode* front = QueneFront(&q);
		QuenePop(&q);
		if (!front)
			break;
		else
		{
			QuenePush(&q, front->left);//这里错了，不管空不空，都要插入
			
			QuenePush(&q, front->right);
		}
		

	}

	while (!QueneEmpty(&q))
	{
		BTNode* front = QueneFront(&q);
		QuenePop(&q);
		if (front)
		{
			QueneDestory(&q);
			return false;
		}
	}

	QueneDestory(&q);
	return true;
}

void BinTreeDestory(BTNode* root)
{
	if (!root)
		return;
	BinTreeDestory(root->left);
	BinTreeDestory(root->right);
	free(root);
}

int main()
{
	BTNode* root = createBinTree();

	PrevOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");
	printf("Size:%d\n", BinTreeSize(root));
	printf("LeafSize:%d\n", BinTreeLeafSize(root));
	printf("Klevel:%d\n", BinTreeLevelKSize(root, 3));
	printf("depth:%d\n", BinTreeDepth(root));
	printf("Find:%d\n", BinTreeFind(root, 6)->data);
	LevelOrder(root);
	printf("\n");
	printf("is Complete?:%d\n", BinTreeComplete(root));
	BinTreeDestory(root);
	root = NULL;
	return 0;
}