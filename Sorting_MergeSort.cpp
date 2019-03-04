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
//		<5. ���� ���� (Merge Sort)>
//			1) ���� ����(divide and conquer)
//			2) ������
//				- �񱳿��� : O(nlog2n) / �̵����� : O(nlog2n) : �������� ���� n���϶� ���� ������ log2�� n��ŭ ����ǹǷ�
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