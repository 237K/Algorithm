//
//	OS Windows
//	2019.03.03
//
//	[정렬 알고리즘]
//		<1. 버블 정렬>
//			1) 매 반복마다 큰 숫자를 뒤로 보냄. 제일 뒤에 있는 숫자는 위치가 확정되었으므로 고정시키고 n-1개에 대해 다시 반복함
//			2) 성능평가
//				- 비교연산 : O(n제곱) / 이동연산 : O(n제곱)
//

#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n)
{
	int temp;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < (n - i) - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main(void)
{
	int arr[5] = { 2, 5, 3, 1, 4 };

	for (int i = 0; i < 5; ++i)
		cout << arr[i] << ' ';
	cout << endl << endl;
	
	cout << "Bubble Sort" << endl<<endl;
	BubbleSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < 5; ++i)
		cout << arr[i] << ' ';
	cout << endl << endl;
	return 0;
}