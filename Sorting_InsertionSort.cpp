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

#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n)
{
	int CurData;
	int idx;
	for (int i = 1; i < n; ++i)
	{
		CurData = arr[i];
		idx = i;
		for (int j = i - 1; j >= 0; --j)
		{
			if (CurData < arr[j])
			{
				arr[j + 1] = arr[j];
				idx = j;
			}
			else
				break;
		}
		arr[idx] = CurData;
		for (int i = 0; i < 5; ++i)
			cout << arr[i] << ' ';
		cout << endl << endl;
	}
}

int main(void)
{
	int arr[5] = { 2, 5, 3, 1, 4 };

	for (int i = 0; i < 5; ++i)
		cout << arr[i] << ' ';
	cout << endl << endl;

	cout << "Insertion Sort" << endl << endl;
	InsertionSort(arr, sizeof(arr) / sizeof(int));
	for (int i = 0; i < 5; ++i)
		cout << arr[i] << ' ';
	cout << endl << endl;
	return 0;
}