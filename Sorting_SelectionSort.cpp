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
//

#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n)
{
	int minIdx;
	int temp;
	
	for (int i = 0; i < n - 1; ++i)
	{
		minIdx = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[minIdx] > arr[j])
			{
				minIdx = j;
			}
		}
		if (minIdx != i)
		{
			temp = arr[i];
			arr[i] = arr[minIdx];
			arr[minIdx] = temp;
		}
	}
}

int main(void)
{
	int arr[5] = { 2, 5, 3, 1, 4 };

	for (int i = 0; i < 5; ++i)
		cout << arr[i] << ' ';
	cout << endl << endl;

	cout << "Selection Sort" << endl << endl;
	SelectionSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < 5; ++i)
		cout << arr[i] << ' ';
	cout << endl << endl;
	return 0;
}