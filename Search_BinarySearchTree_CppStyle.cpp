//
//	OS Windows
//	2019.03.09
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
//			3) ���� Ž�� Ʈ���� ����
//				a) ������ ���� ����� ��
//					1) ������ ��尡 �ܸ������ ���
//						step 1) �׳� ����
//					2) ������ ��尡 �ϳ��� ����Ʈ���� ���� ���
//						- ������ ��带 �����ϰ�, ������ ����� �θ���� ������ ����� �ڽĳ�带 ����
//						step 1) ������ ����� �θ������ ������ ������ ����� �ڽĳ��� ��ü�ϸ� ��
//					3) ������ ��尡 �� ���� ����Ʈ���� ���� ���
//						step 1) ������ ��带 ��ü�� ��带 ã��
//							- ������ ����� ���� ����Ʈ������ ���� ū �� / �����ʼ���Ʈ������ ���� ���� ���� ���� �� ����
//						step 2) ��ü�� ��忡 '����� ��'�� ������ ��忡 ������
//						step 3) ��ü�� ����� �θ���� �ڽĳ�带 ����
//

/////////////Binary Tree////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

template <typename T>
class BinaryTree;

typedef void VisitFuncPtr(int data);

template <typename T>
class Node
{
	friend class BinaryTree<T>;
public:
	T data;
	int check;
	BinaryTree<T> *left;
	BinaryTree<T> *right;
public:
	Node(T data, BinaryTree<T>* left = NULL, BinaryTree<T>* right = NULL)
	{
		this->data = data;
		check = 1;
		this->left = left;
		this->right = right;
	}
	~Node()
	{
		delete left;
		delete right;
	}
};

template <typename T>
class BinaryTree
{
	friend class Node<T>;
public:
	Node<T> *BTnode;
public:
	BinaryTree(T data = 0)
	{
		BTnode = new Node<T>(data);
	}
	~BinaryTree()
	{
		delete BTnode;
	}
	void SetData(T data)
	{
		BTnode->data = data;
	}
	T GetData()
	{
		if (BTnode != NULL)
			return BTnode->data;
		else
		{
			cout << "Node is empty" << endl << endl;
			return -1;
		}
	}
	BinaryTree<T>* GetCurSubTree()
	{
		return BTnode;
	}
	BinaryTree<T>* GetLeftSubTree()
	{
		return BTnode->left;
	}
	BinaryTree<T>* GetRightSubTree()
	{
		return BTnode->right;
	}
	void MakeLeftSubTree(BinaryTree<T>* bt)
	{
		if (BTnode != NULL)
		{
			if (BTnode->left != NULL)
			{
				delete BTnode->left;
				BTnode->left = NULL;
			}
			BTnode->left = bt;
		}
		else
		{
			cout << "root node is empty" << endl << endl;
			exit(-1);
		}
	}
	void MakeRightSubTree(BinaryTree<T>* bt)
	{
		if (BTnode != NULL)
		{
			if (BTnode->right != NULL)
			{
				delete BTnode->right;
				BTnode->right = NULL;
			}
			BTnode->right = bt;
		}
		else
		{
			cout << "root node is empty" << endl << endl;
			exit(-1);
		}
	}

	void InorderTraverse(BinaryTree<T> *bt, VisitFuncPtr action)
	{
		BinaryTree<T> *temp = new BinaryTree<T>();
		temp = bt;

		if (temp == NULL)
		{
			return;
		}
		else
		{
			InorderTraverse(temp->BTnode->left, action);
			action(temp->BTnode->data);
			InorderTraverse(temp->BTnode->right, action);
		}
	}
	void DeleteTree(BinaryTree<T> *bt)
	{
		if (bt == NULL)
		{
			return;
		}
		else
		{
			DeleteTree(bt->BTnode->left);
			DeleteTree(bt->BTnode->right);
			cout << "Delete " << bt->BTnode->data << endl;
			delete bt;
			bt = NULL;
		}
	}
/////////////Binary Tree////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////Binary Search Tree/////////////////////////////////////////////////////////////////////////////////////////////
	T BSTGetNodeData();
	void BSTInsert(BinaryTree<T> **pRoot, T data);
	BinaryTree<T>* BSTSearch(BinaryTree<T> *bst, T target);
/////////////Binary Search Tree/////////////////////////////////////////////////////////////////////////////////////////////

/////////////Delete/////////////////////////////////////////////////////////////////////////////////////////////////////////
	BinaryTree<T>* RemoveLeftSubTree();
	BinaryTree<T>* RemoveRightSubTree();
	void ChangeLeftSubTree(BinaryTree<T>* main, BinaryTree<T>* sub);
	void ChangeRightSubTree(BinaryTree<T>* main, BinaryTree<T>* sub);
/////////////Delete/////////////////////////////////////////////////////////////////////////////////////////////////////////
};

/////////////Binary Search Tree/////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
T BinaryTree<T>::BSTGetNodeData()
{
	return BTnode->data;
}
template <typename T>
void BinaryTree<T>::BSTInsert(BinaryTree<T> **pRoot, T data)
{
	BinaryTree<T> *parentNode = new BinaryTree<T>();
	BinaryTree<T> *currentNode = new BinaryTree<T>();
	currentNode = *pRoot;
	BinaryTree<T> *newNode = new BinaryTree<T>();

	while (currentNode != NULL)
	{
		if (currentNode->BTnode->data == data)
			return;

		parentNode = currentNode;

		if (currentNode->BTnode->data > data)
			currentNode = currentNode->GetLeftSubTree();
		else if (currentNode->BTnode->data < data)
			currentNode = currentNode->GetRightSubTree();
	}

	newNode->SetData(data);

	if (parentNode != NULL)
	{
		if (data < parentNode->GetData())
			parentNode->MakeLeftSubTree(newNode);
		else
			parentNode->MakeRightSubTree(newNode);
	}
	else
		*pRoot = newNode;
}
template <typename T>
BinaryTree<T>* BinaryTree<T>::BSTSearch(BinaryTree<T> *bst, T target)
{
	BinaryTree<T> *currentNode = new BinaryTree<T>();
	currentNode = bst;
	T cur_data;

	while (currentNode != NULL)
	{
		cur_data = currentNode->GetData();

		if (cur_data == target)
			return currentNode;
		else if (cur_data > target)
			currentNode = currentNode->GetLeftSubTree();
		else
			currentNode = currentNode->GetRightSubTree();
	}
	return NULL;
}
/////////////Binary Search Tree/////////////////////////////////////////////////////////////////////////////////////////////

/////////////Delete/////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
BinaryTree<T>* BinaryTree<T>::RemoveLeftSubTree()
{

}
template <typename T>
BinaryTree<T>* BinaryTree<T>::RemoveRightSubTree()
{

}
template <typename T>
void BinaryTree<T>::ChangeLeftSubTree(BinaryTree<T>* main, BinaryTree<T>* sub)
{
	main->BTnode->left = sub;
}
template <typename T>
void BinaryTree<T>::ChangeRightSubTree(BinaryTree<T>* main, BinaryTree<T>* sub)
{
	main->BTnode->right = sub;
}
/////////////Delete/////////////////////////////////////////////////////////////////////////////////////////////////////////
void ShowIntData(int data)
{
	cout << data << ' ';
}

int main(void)
{
	BinaryTree<int> *bstRoot = new BinaryTree<int>();
	BinaryTree<int> *searchNode = new BinaryTree<int>();

	bstRoot->BSTInsert(&bstRoot, 7);
	bstRoot->BSTInsert(&bstRoot, 1);
	bstRoot->BSTInsert(&bstRoot, 9);
	bstRoot->BSTInsert(&bstRoot, 4);
	bstRoot->BSTInsert(&bstRoot, 5);
	bstRoot->BSTInsert(&bstRoot, 8);
	bstRoot->BSTInsert(&bstRoot, 2);
	bstRoot->BSTInsert(&bstRoot, 3);
	bstRoot->BSTInsert(&bstRoot, 6);

	cout << "Search 1" << endl;
	searchNode = bstRoot->BSTSearch(bstRoot, 1);
	if (searchNode == NULL)
		cout << "Fail" << endl << endl;
	else
		cout << "Key : " << searchNode->BSTGetNodeData() << endl << endl;

	cout << "Search 2" << endl;
	searchNode = bstRoot->BSTSearch(bstRoot, 2);
	if (searchNode == NULL)
		cout << "Fail" << endl << endl;
	else
		cout << "Key : " << searchNode->BSTGetNodeData() << endl << endl;

	cout << "Search 3" << endl;
	searchNode = bstRoot->BSTSearch(bstRoot, 3);
	if (searchNode == NULL)
		cout << "Fail" << endl << endl;
	else
		cout << "Key : " << searchNode->BSTGetNodeData() << endl << endl;

	cout << "Search 4" << endl;
	searchNode = bstRoot->BSTSearch(bstRoot, 4);
	if (searchNode == NULL)
		cout << "Fail" << endl << endl;
	else
		cout << "Key : " << searchNode->BSTGetNodeData() << endl << endl;

	cout << "Search 10" << endl;
	searchNode = bstRoot->BSTSearch(bstRoot, 10);
	if (searchNode == NULL)
		cout << "Fail" << endl << endl;
	else
		cout << "Key : " << searchNode->BSTGetNodeData() << endl << endl;

	return 0;
}