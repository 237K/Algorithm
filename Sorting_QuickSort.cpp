//
//	OS Windows
//	2019.03.04
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
//		<5. ���� ���� (Merge Sort)>
//			1) ���� ����(divide and conquer)
//			2) ������
//				- �񱳿��� : O(nlog2n) / �̵����� : O(nlog2n) : �������� ���� n���϶� ���� ������ log2�� n��ŭ ����ǹǷ�
//		<6. �� ����>
//			1) ���� ����
//			2) �ǹ��� ���ϰ�(�Ϲ������� ���Ĵ�󿡼� �� ���� �����͸� ������ �� �� �߿��� �߰� ���� �ǹ����� ������)
//			3) ������
//				- O(nlog2n)
//

#include <iostream>
using namespace std;

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (pivot >= arr[low] && low <= right)
		{
			low++;
		}
		while (pivot <= arr[high] && high >= (left+1))
		{
			high--;
		}

		if (low <= high)
		{
			Swap(arr, low, high);
		}
	}
	Swap(arr, left, high);
	return high;
}

void QuickSort(int arr[], int left, int right)
{
	if (left > right)
		return;
	else
	{
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

int main(void)
{
	int arr[10] = { 2, 5, 3, 1, 4, 8, 9, 6, 10, 7 };

	for (int i = 0; i < 10; ++i)
		cout << arr[i] << ' ';
	cout << endl << endl;

	cout << "Quick Sort" << endl << endl;
	QuickSort(arr, 0, 9);

	for (int i = 0; i < 10; ++i)
		cout << arr[i] << ' ';
	cout << endl << endl;

	return 0;
}