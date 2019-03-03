//
//	OS Windows
//	2019.03.03
//
//	[���� �˰���]
//		<1. ���� ����>
//			1) �� �ݺ����� ū ���ڸ� �ڷ� ����. ���� �ڿ� �ִ� ���ڴ� ��ġ�� Ȯ���Ǿ����Ƿ� ������Ű�� n-1���� ���� �ٽ� �ݺ���
//				�ڿ������� ä�������ٴ� ����
//			2) ������
//				- �񱳿��� : O(n����) / �̵����� : O(n����)
//		<2. ���� ���� (Selection Sort)>
//			1) ���ļ����� �°� �ϳ��� �����ؼ� �ű�. ���� �����ϸ� �޸𸮰����� �ϳ� �� �ʿ��� �� ������,
//				���ļ����� ���� �켱������ ���� ���� ���� �������� �̵���Ű��, ���� �����ʹ� ��������� �ű�� ������ �����ϸ� ��
//				���� ������ �ڿ������� ä��ٸ�, ���������� �տ������� ä��ٴ� ��������
//			2) ������
//				- �񱳿��� : O(n����) / �̵����� : O(n)
//		<3. ���� ���� (Insertion Sort)>
//			1) ������ �Ϸ�� �κа� �Ϸ���� ���� �κ����� ����.
//				���� �� �� �κп� �ִ� �����͸� ���� �� �κ��� Ư�� ��ġ�� ����
//			2) ������ �Ϸ�� ������ ������ ��ġ�� �����Ͱ� �� ���� ���Ĵ����. �����͸� �� ĭ�� �ڷ� �и鼭 ������ ��ġ�� ã���� ��
//			3) ������
//				- �񱳿��� : O(n����) / �̵����� : O(n����)
//		<4. �� ����>
//			1) �迭�� ������ �����Ѵ��� ��Ʈ��带 �ϳ��� ������ �迭�� ����
//			2) ������
//				- O(nlog2n) : ������ ����/�����ð��� ���̸�ŭ �ɸ��µ�, ���� ���̴� ���� ������ 2�� n�°��� �� ������ �������Ƿ� log2n �̰�,
//							  �����ؾ��ϴ� �����Ͱ� n���̸� n * log2n ��ŭ �ɸ�
//

#include <iostream>
#include <vector>
using namespace std;

//heap////////////////////////////////////////////////////////////////////
const static int MAX = 100;
typedef int PriorityComp(int d1, int d2);
class Heap	
{
private:
	vector<int> heapVector;
	int numOfdata;
	PriorityComp *comp;
public:
	void Init(PriorityComp pc);
	bool Empty();
	void Insert(int data);
	int Delete();
	void Print() const;

	int GetParentIdx(int idx);
	int GetLeftChildIdx(int idx);
	int GetRightChildIdx(int idx);
	int CompareLeftRight(int idx);
};

void Heap::Init(PriorityComp pc)
{
	numOfdata = 0;
	comp = pc;
	heapVector.resize(MAX);
}

bool Heap::Empty()
{
	if (numOfdata == 0)
		return true;
	else
		return false;
}

void Heap::Print() const
{
	for (int i = 0; i <= numOfdata; ++i)
	{
		cout << heapVector[i] << ' ';
	}
	cout << endl << endl;
}

int Heap::GetParentIdx(int idx)
{
	return idx / 2;
}

int Heap::GetLeftChildIdx(int idx)
{
	return idx * 2;
}

int Heap::GetRightChildIdx(int idx)
{
	return idx * 2 + 1;
}

int Heap::CompareLeftRight(int idx)
{
	int Left = GetLeftChildIdx(idx);
	int Right = GetRightChildIdx(idx);

	if (Left > numOfdata)
		return 0;
	else if (Left == numOfdata)
		return Left;
	else
	{
		if (comp(heapVector[Left], heapVector[Right]) > 0)
			return Left;
		else
			return Right;
	}
}

void Heap::Insert(int data)
{
	int idx = numOfdata + 1;
	while (idx != 1)
	{
		if (comp(data, heapVector[GetParentIdx(idx)]) > 0)
		{
			heapVector[idx] = heapVector[GetParentIdx(idx)];
			idx = GetParentIdx(idx);
		}
		else
			break;
	}
	heapVector[idx] = data;
	numOfdata += 1;
}

int Heap::Delete()
{
	int tempData = heapVector[1];
	int lastElem = heapVector[numOfdata];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = CompareLeftRight(parentIdx))
	{
		if (comp(lastElem, heapVector[childIdx]) >= 0)
			break;
		else
		{
			heapVector[parentIdx] = heapVector[childIdx];
			parentIdx = childIdx;
		}
	}
	heapVector[parentIdx] = lastElem;
	numOfdata -= 1;
	return tempData;
}
//heap////////////////////////////////////////////////////////////////////


//heap sort////////////////////////////////////////////////////////////////////

void HeapSort(int arr[], int n, PriorityComp pc)
{
	Heap heap;
	heap.Init(pc);

	for (int i = 0; i < n; ++i)
		heap.Insert(arr[i]);

	for (int i = 0; i < n; ++i)
		arr[i] = heap.Delete();
}
//heap sort////////////////////////////////////////////////////////////////////


int Priority(int d1, int d2)
{
	return d2 - d1;
}

int main(void)
{
	int arr[5] = { 2, 5, 3, 1, 4 };

	for (int i = 0; i < 5; ++i)
		cout << arr[i] << ' ';
	cout << endl << endl;

	cout << "Heap Sort" << endl << endl;
	HeapSort(arr, sizeof(arr) / sizeof(int), Priority);
	for (int i = 0; i < 5; ++i)
		cout << arr[i] << ' ';
	cout << endl << endl;
	return 0;
}