//
//	OS Windows
//	2019.03.09
//
//	[Ž�� �˰���]
//		<1. ���� Ž��>
//		<2. ���� Ž�� (Interpolation Search)>
//		<3. ���� Ž�� Ʈ��>
//		<4. ���� ���� ���� Ž�� Ʈ��>
//			1) ���� Ž�� Ʈ���� ���� ����Ʈ���� ������ ����Ʈ���� ������ ���� �������� O(n)�� ����� �ð����⵵�� ����
//			2) ���� ���� ���� Ž�� Ʈ�� ����
//				a) AVL Ʈ��
//				b) 2-3 Ʈ��
//				c) 2-3-4 Ʈ��
//				d) Red-Black Ʈ��
//				e) B Ʈ��
//		<4-1. AVL Ʈ��>
//			1) ��尡 �߰��� ��, ������ �� Ʈ���� �������¸� �ľ��ؼ� ������ ������ �����Ͽ� ������ ����
//			2) ���� �μ�(Balance Factor) ���.
//				- ���� �μ� = ���� ����Ʈ���� ���� - ������ ����Ʈ���� ����
//				- ���� �μ��� ���밪�� Ŭ���� Ʈ���� ������ ������ ���¶�� �� �� ����.
//				- ���� �μ��� ���밪�� 2 �̻��� ��쿡 ���뷱���� ����
//			3) ���뷱���� �ʿ��� ���̽�
//				a) LLȸ�� (Left Left) : �ڽ� ��� �� ���� �������� ���̾� ����� ���
//				b) RRȸ��
//				c) LRȸ�� : RRȸ�� �� ���� LLȸ��
//				d) RLȸ�� : LLȸ�� �� ���� RRȸ��
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
	T BSTGetNodeData(BinaryTree<T> *bst);
	void BSTInsert(BinaryTree<T> **pRoot, T data);
	BinaryTree<T>* BSTSearch(BinaryTree<T> *bst, T target);
	void BSTShowAll(BinaryTree<T> *bst);
	/////////////Binary Search Tree/////////////////////////////////////////////////////////////////////////////////////////////

	/////////////Delete/////////////////////////////////////////////////////////////////////////////////////////////////////////
	BinaryTree<T>* RemoveLeftSubTree();
	BinaryTree<T>* RemoveRightSubTree();
	void ChangeLeftSubTree(BinaryTree<T>* main, BinaryTree<T>* sub);
	void ChangeRightSubTree(BinaryTree<T>* main, BinaryTree<T>* sub);

	BinaryTree<T>* BSTRemove(BinaryTree<T> **pRoot, T target);
	/////////////Delete/////////////////////////////////////////////////////////////////////////////////////////////////////////

	/////////////AVL Ʈ�� ��� �߰�//////////////////////////////////////////////////////////////////////////////////////////////
	int GetHeight(BinaryTree<T> *bst);
	int GetBalanceFactor(BinaryTree<T> *bst);
	BinaryTree<T>* LLrotate(BinaryTree<T> *bst);
	BinaryTree<T>* RRrotate(BinaryTree<T> *bst);
	BinaryTree<T>* LRrotate(BinaryTree<T> *bst);
	BinaryTree<T>* RLrotate(BinaryTree<T> *bst);

	BinaryTree<T>* Rebalance(BinaryTree<T> **pRoot);
	/////////////AVL Ʈ�� ��� �߰�//////////////////////////////////////////////////////////////////////////////////////////////
};

/////////////Binary Search Tree/////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
T BinaryTree<T>::BSTGetNodeData(BinaryTree<T> *bst)
{
	return bst->BTnode->data;
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

	*pRoot = Rebalance(pRoot);
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
void ShowIntData(int data)
{
	cout << data << ' ';
}

template <typename T>
void BinaryTree<T>::BSTShowAll(BinaryTree<T> *bst)
{
	InorderTraverse(bst, ShowIntData);
}
/////////////Binary Search Tree/////////////////////////////////////////////////////////////////////////////////////////////

/////////////Delete/////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
BinaryTree<T>* BinaryTree<T>::RemoveLeftSubTree()
{
	BinaryTree<T> *delNode = new BinaryTree<T>();
	if (BTnode != NULL)
	{
		delNode = BTnode->left;
		BTnode->left = NULL;
	}
	return delNode;
}
template <typename T>
BinaryTree<T>* BinaryTree<T>::RemoveRightSubTree()
{
	BinaryTree<T> *delNode = new BinaryTree<T>();
	if (BTnode != NULL)
	{
		delNode = BTnode->right;
		BTnode->right = NULL;
	}
	return delNode;
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
template <typename T>
BinaryTree<T>* BinaryTree<T>::BSTRemove(BinaryTree<T> **pRoot, T target)
{
	BinaryTree<T> *VirtualRootNode = new BinaryTree<T>();		//���� ����� ��Ʈ ����� ��츦 ����Ͽ� �����Ʈ��� ���� ����
	BinaryTree<T> *parentNode = new BinaryTree<T>();
	parentNode = VirtualRootNode;
	BinaryTree<T> *currentNode = new BinaryTree<T>();
	currentNode = *pRoot;
	BinaryTree<T> *delNode = new BinaryTree<T>();

	VirtualRootNode->ChangeRightSubTree(VirtualRootNode, *pRoot);

	//Search target
	while (currentNode != NULL && currentNode->GetData() != target)
	{
		parentNode = currentNode;

		if (currentNode->GetData() > target)
			currentNode = currentNode->BTnode->left;
		else
			currentNode = currentNode->BTnode->right;
	}
	if (currentNode == NULL)
		return NULL;

	delNode = currentNode;

	//Case 1) ������ ��尡 �ܸ������ ���
	if (delNode->BTnode->left == NULL && delNode->BTnode->right == NULL)
	{
		if (parentNode->BTnode->left == delNode)
			parentNode->RemoveLeftSubTree();
		else
			parentNode->RemoveRightSubTree();
	}

	//Case 2) ������ ��尡 �ϳ��� �ڽĳ�带 ���� ���
	else if (delNode->BTnode->left == NULL || delNode->BTnode->right == NULL)
	{
		BinaryTree<T> *childNode = new BinaryTree<T>();

		if (delNode->BTnode->left != NULL)
			childNode = delNode->BTnode->left;
		else
			childNode = delNode->BTnode->right;

		if (parentNode->BTnode->left == delNode)
			parentNode->ChangeLeftSubTree(parentNode, childNode);
		else
			parentNode->ChangeRightSubTree(parentNode, childNode);
	}

	//Case 3) ������ ��尡 �� ���� �ڽĳ�带 ���� ���
	else
	{
		BinaryTree<T> *replaceNode = new BinaryTree<T>();
		replaceNode = delNode->BTnode->right;
		BinaryTree<T> *replaceParentNode = new BinaryTree<T>();
		replaceParentNode = delNode;

		int delData;

		//������ ����� ��ü ��� �˻�
		while (replaceNode->BTnode->left != NULL)
		{
			replaceParentNode = replaceNode;
			replaceNode = replaceNode->BTnode->left;
		}

		//��ü�� ��忡 ����� ���� ������ ��忡 ����
		delData = delNode->GetData();
		delNode->SetData(replaceNode->GetData());

		//��ü�� ����� �θ���� �ڽĳ�带 ����
		if (replaceParentNode->BTnode->left == replaceNode)
			replaceParentNode->ChangeLeftSubTree(replaceParentNode, replaceNode->BTnode->right);
		else
			replaceParentNode->ChangeRightSubTree(replaceParentNode, replaceNode->BTnode->right);

		delNode = replaceNode;
		delNode->SetData(delData);
	}

	//������ ��尡 ��Ʈ����� ���
	if (VirtualRootNode->BTnode->right != *pRoot)
		*pRoot = VirtualRootNode->BTnode->right;

	//delete VirtualRootNode;
	//VirtualRootNode = NULL;
	*pRoot = Rebalance();
	return delNode;
}
/////////////Delete/////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////AVL Ʈ�� ��� �߰�//////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
int BinaryTree<T>::GetHeight(BinaryTree<T> *bst)
{
	int leftH;
	int rightH;

	if (bst == NULL)
		return 0;

	leftH = bst->BTnode->left->GetHeight(bst->BTnode->left);
	rightH = bst->BTnode->right->GetHeight(bst->BTnode->left);

	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}
template <typename T>
int BinaryTree<T>::GetBalanceFactor(BinaryTree<T> *bst)
{
	int lsh;
	int rsh;

	if (bst == NULL)
		return 0;

	lsh = bst->BTnode->left->GetHeight(bst->BTnode->left);
	rsh = bst->BTnode->right->GetHeight(bst->BTnode->right);
	return lsh - rsh;
}
template <typename T>
BinaryTree<T>* BinaryTree<T>::LLrotate(BinaryTree<T> *bst)
{
	BinaryTree<T> *pNode = new BinaryTree<T>();
	BinaryTree<T> *cNode = new BinaryTree<T>();

	pNode = bst;
	cNode = pNode->BTnode->left;

	pNode->ChangeLeftSubTree(pNode, cNode->BTnode->right);
	cNode->ChangeRightSubTree(cNode, pNode);
	return cNode;
}
template <typename T>
BinaryTree<T>* BinaryTree<T>::RRrotate(BinaryTree<T> *bst)
{
	BinaryTree<T> *pNode = new BinaryTree<T>();
	BinaryTree<T> *cNode = new BinaryTree<T>();

	pNode = bst;
	cNode = pNode->BTnode->right;

	pNode->ChangeRightSubTree(pNode, cNode->BTnode->left);
	cNode->ChangeLeftSubTree(cNode, pNode);
	return cNode;
}
template <typename T>
BinaryTree<T>* BinaryTree<T>::LRrotate(BinaryTree<T> *bst)
{
	BinaryTree<T> *pNode = new BinaryTree<T>();
	BinaryTree<T> *cNode = new BinaryTree<T>();

	pNode = bst;
	cNode = pNode->BTnode->left;

	pNode->ChangeLeftSubTree(pNode, cNode->RRrotate(cNode));
	return pNode->LLrotate(pNode);
}
template <typename T>
BinaryTree<T>* BinaryTree<T>::RLrotate(BinaryTree<T> *bst)
{
	BinaryTree<T> *pNode = new BinaryTree<T>();
	BinaryTree<T> *cNode = new BinaryTree<T>();

	pNode = bst;
	cNode = pNode->BTnode->right;

	pNode->ChangeRightSubTree(pNode, cNode->LLrotate(cNode));
	return pNode->RRrotate(pNode);
}
template <typename T>
BinaryTree<T>* BinaryTree<T>::Rebalance(BinaryTree<T> **pRoot)
{
	BinaryTree<T> *currentNode = new BinaryTree<T>();
	currentNode = *pRoot;
	int BF = currentNode->GetBalanceFactor(currentNode);

	if (BF > 1)
	{
		if (currentNode->BTnode->left->GetBalanceFactor(currentNode->BTnode->left) > 0)
			currentNode = LLrotate(currentNode);
		else
			currentNode = LRrotate(currentNode);
	}

	if (BF < -1)
	{
		if (currentNode->BTnode->right->GetBalanceFactor(currentNode->BTnode->right) < 0)
			currentNode = RRrotate(currentNode);
		else
			currentNode = RLrotate(currentNode);
	}
	return currentNode;
}
/////////////AVL Ʈ�� ��� �߰�//////////////////////////////////////////////////////////////////////////////////////////////

int main(void)
{
	BinaryTree<int> *bstRoot = new BinaryTree<int>();
	BinaryTree<int> *leftNode = new BinaryTree<int>();
	BinaryTree<int> *rightNode = new BinaryTree<int>();

	bstRoot->BSTInsert(&bstRoot, 1);
	bstRoot->BSTInsert(&bstRoot, 2);
	bstRoot->BSTInsert(&bstRoot, 3);
	bstRoot->BSTInsert(&bstRoot, 4);
	bstRoot->BSTInsert(&bstRoot, 5);
	bstRoot->BSTInsert(&bstRoot, 6);
	bstRoot->BSTInsert(&bstRoot, 7);
	bstRoot->BSTInsert(&bstRoot, 8);
	bstRoot->BSTInsert(&bstRoot, 9);

	cout << "Current Binary Tree : ";
	bstRoot->BSTShowAll(bstRoot);
	cout << endl << endl;

	return 0;
}
