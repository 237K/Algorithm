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
//		<5. 병합 정렬 (Merge Sort)>
//			1) 분할 정복(divide and conquer)
//			2) 성능평가
//				- 비교연산 : O(nlog2n) / 이동연산 : O(nlog2n) : 데이터의 수가 n개일때 병합 과정은 log2의 n만큼 진행되므로
//

#include <iostream>
#include <vector>
using namespace std;

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;
	int *tempArr = new int[right + 1];
	int curIdx = left;
	while (leftIdx <= mid && rightIdx <= right)
	{
		if (arr[leftIdx] <= arr[rightIdx])
		{
			tempArr[curIdx] = arr[leftIdx];
			leftIdx++;
		}
		else
		{
			tempArr[curIdx] = arr[rightIdx];
			rightIdx++;
		}
		curIdx++;
	}

	if (leftIdx > mid)
	{
		for (int i = rightIdx; i <= right; ++i, curIdx++)
		{
			tempArr[curIdx] = arr[i];
		}
	}
	else
	{
		for (int i = leftIdx; i <= mid; ++i, curIdx++)
		{
			tempArr[curIdx] = arr[i];
		}
	}

	for (int i = left; i <= right; ++i)
	{
		arr[i] = tempArr[i];
	}
	delete[] tempArr;
}

void MergeSort(int arr[], int left, int right)
{
	int mid;
	
	if (left < right)
	{
		mid = (left + right) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		MergeTwoArea(arr, left, mid, right);
	}
}

int main(void)
{
	int arr[10] = { 2, 5, 3, 1, 4, 8, 9, 6, 10, 7 };

	for (int i = 0; i < 10; ++i)
		cout << arr[i] << ' ';
	cout << endl << endl;

	cout << "Merge Sort" << endl << endl;
	MergeSort(arr, 0, 9);

	for (int i = 0; i < 10; ++i)
		cout << arr[i] << ' ';
	cout << endl << endl;

	return 0;
}