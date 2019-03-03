//
//	OS Windows
//	2019.03.03
//
//	[정렬 알고리즘]
//		<1. 버블 정렬>
//			1) 매 반복마다 큰 숫자를 뒤로 보냄. 제일 뒤에 있는 숫자는 위치가 확정되었으므로 고정시키고 n-1개에 대해 다시 반복함
//				뒤에서부터 채워나간다는 느낌
//			2) 성능평가
//				- 비교연산 : O(n제곱) / 이동연산 : O(n제곱)
//		<2. 선택 정렬 (Selection Sort)>
//			1) 정렬순서에 맞게 하나씩 선택해서 옮김. 쉽게 생각하면 메모리공간이 하나 더 필요할 수 있으나,
//				정렬순서상 가장 우선순위가 높은 것을 가장 왼쪽으로 이동시키고, 원래 데이터는 빈공간으로 옮기는 식으로 진행하면 됨
//				버블 정렬이 뒤에서부터 채운다면, 선택정렬은 앞에서부터 채운다는 느낌으로
//			2) 성능평가
//				- 비교연산 : O(n제곱) / 이동연산 : O(n)
//		<3. 삽입 정렬 (Insertion Sort)>
//			1) 정렬이 완료된 부분과 완료되지 않은 부분으로 나눔.
//				정렬 안 된 부분에 있는 데이터를 정렬 된 부분의 특정 위치에 삽입
//			2) 정렬이 완료된 영역의 다음에 위치한 데이터가 그 다음 정렬대상임. 데이터를 한 칸씩 뒤로 밀면서 삽입할 위치를 찾으면 됨
//			3) 성능평가
//				- 비교연산 : O(n제곱) / 이동연산 : O(n제곱)
//		<4. 힙 정렬>
//			1) 배열을 힙으로 구성한다음 루트노드를 하나씩 꺼내서 배열에 넣음
//			2) 성능평가
//				- O(nlog2n) : 힙에서 삽입/삭제시간은 높이만큼 걸리는데, 힙의 높이는 원소 개수가 2의 n승개가 될 때마다 높아지므로 log2n 이고,
//							  정렬해야하는 데이터가 n개이면 n * log2n 만큼 걸림
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