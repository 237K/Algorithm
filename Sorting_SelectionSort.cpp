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