//
//	OS Windows
//	2019.03.08
//
//	[Ž�� �˰���]
//		<1. ���� Ž��>
//		<2. ���� Ž�� (Interpolation Search)>
//		<3. ���� Ž�� Ʈ��>
//			1) ���� Ʈ���� ������ ���� ��Ģ�� ���� ���� ���� Ž�� Ʈ��.
//			2) ���� Ž�� Ʈ���� ����
//				a) ��忡 ����� key�� �����ϴ�.
//				b) ��Ʈ����� key�� ���� ����Ʈ�� ��� ����� key���� ũ��. (�θ����� key�� ���� �ڽĳ���� key���� ũ��)
//				c) ��Ʈ����� key�� ������ ����Ʈ�� ��� ����� key���� �۴�. (�θ����� key�� ������ �ڽĳ���� key���� �۴�)
//				d) ���ʰ� ������ ����Ʈ���� ���� Ž�� Ʈ���̴�.

#include <iostream>
#include <cstdio>
using namespace std;

/////////////Binary Tree////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct _btreeNode
{
	int data;
	struct _btreeNode *left;
	struct _btreeNode *right;
} BTreeNode;

BTreeNode *MakeBTreeNode(void);
int GetData(BTreeNode *bt);
void SetData(BTreeNode *bt, int data);

BTreeNode *GetLeftSubTree(BTreeNode *bt);
BTreeNode *GetRightSubTree(BTreeNode *bt);

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub);
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);

void InorderTraverse(BTreeNode *bt);								//Ʈ�� ������ȸ �Լ�

typedef void VisitFuncPtr(int data);
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action);			//Ʈ�� ������ȸ �Լ� (��忡 ������ �Լ� �߰�)

void DeleteTree(BTreeNode *bt);

BTreeNode *MakeBTreeNode(void)
{
	BTreeNode *newNode = new BTreeNode;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

int GetData(BTreeNode *bt)
{
	return bt->data;
}

void SetData(BTreeNode *bt, int data)
{
	bt->data = data;
}

BTreeNode *GetLeftSubTree(BTreeNode *bt)
{
	return bt->left;
}

BTreeNode *GetRightSubTree(BTreeNode *bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub)
{
	if (main->left != NULL)
		delete main->left;
	main->left = sub;
}

void MakeRightSubTree(BTreeNode *main, BTreeNode *sub)
{
	if (main->right != NULL)
		delete main->right;
	main->right = sub;
}

void InorderTraverse(BTreeNode *bt)
{
	if (bt == NULL)
		return;
	else
	{
		InorderTraverse(bt->left);
		cout << bt->data << ' ';
		InorderTraverse(bt->right);
	}
}

void InorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;
	else
	{
		InorderTraverse(bt->left, action);
		action(bt->data);
		InorderTraverse(bt->right, action);
	}
}

void DeleteTree(BTreeNode *bt)				//������ ������ȸ�� �ؾ���
{
	if (bt == NULL)
		return;
	else
	{
		DeleteTree(bt->left);
		DeleteTree(bt->right);
		cout << "delete " << bt->data << endl;
		delete bt;
		bt = NULL;
	}
}

void ShowIntData(int data)
{
	if (data < 0)
		cout << "Deleted " << endl;
	else
		cout << data << ' ';
}
/////////////Binary Tree////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////Binary Search Tree/////////////////////////////////////////////////////////////////////////////////////////////
void BSTMake(BTreeNode **pRoot)
{
	*pRoot = NULL;
}
int BSTGetNodeData(BTreeNode *bst)
{
	return GetData(bst);
}
void BSTInsert(BTreeNode **pRoot, int data)
{
	BTreeNode *pNode = NULL;
	BTreeNode *cNode = *pRoot;
	BTreeNode *nNode = NULL;

	while (cNode != NULL)
	{
		if (GetData(cNode) == data)
			return;

		pNode = cNode;

		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else if (GetData(cNode) < data)
			cNode = GetRightSubTree(cNode);
	}
	nNode = MakeBTreeNode();
	SetData(nNode, data);

	if (pNode != NULL)
	{
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else if (data > GetData(pNode))
			MakeRightSubTree(pNode, nNode);
	}
	else
		*pRoot = nNode;
}
BTreeNode *BSTSearch(BTreeNode *bst, int target)
{
	BTreeNode *cNode = bst;
	int cur_data;

	while (cNode != NULL)
	{
		cur_data = GetData(cNode);

		if (cur_data == target)
			return cNode;
		else if (cur_data > target)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}
	return NULL;
}
/////////////Binary Search Tree/////////////////////////////////////////////////////////////////////////////////////////////

int main(void)
{
	BTreeNode *bstRoot;
	BTreeNode *sNode;

	BSTMake(&bstRoot);

	BSTInsert(&bstRoot, 7);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 4);
	BSTInsert(&bstRoot, 5);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 6);

	cout << "Search 1" << endl;
	sNode = BSTSearch(bstRoot, 1);
	if (sNode == NULL)
		cout << "Fail" << endl << endl;
	else
		cout << "Key : " << BSTGetNodeData(sNode)<<endl<<endl;

	cout << "Search 2" << endl;
	sNode = BSTSearch(bstRoot, 2);
	if (sNode == NULL)
		cout << "Fail" << endl << endl;
	else
		cout << "Key : " << BSTGetNodeData(sNode)<<endl<<endl;

	cout << "Search 3" << endl;
	sNode = BSTSearch(bstRoot, 3);
	if (sNode == NULL)
		cout << "Fail" << endl << endl;
	else
		cout << "Key : " << BSTGetNodeData(sNode)<<endl<<endl;

	cout << "Search 4" << endl;
	sNode = BSTSearch(bstRoot, 4);
	if (sNode == NULL)
		cout << "Fail" << endl << endl;
	else
		cout << "Key : " << BSTGetNodeData(sNode)<<endl<<endl;

	cout << "Search 10" << endl;
	sNode = BSTSearch(bstRoot, 10);
	if (sNode == NULL)
		cout << "Fail" << endl << endl;
	else
		cout << "Key : " << BSTGetNodeData(sNode)<<endl<<endl;

	return 0;
}