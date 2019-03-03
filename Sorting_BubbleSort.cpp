//
//	OS Windows
//	2019.03.03
//
//	[���� �˰���]
//		<1. ���� ����>
//			1) �� �ݺ����� ū ���ڸ� �ڷ� ����. ���� �ڿ� �ִ� ���ڴ� ��ġ�� Ȯ���Ǿ����Ƿ� ������Ű�� n-1���� ���� �ٽ� �ݺ���
//			2) ������
//				- �񱳿��� : O(n����) / �̵����� : O(n����)
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