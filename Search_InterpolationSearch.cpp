//
//	OS Windows
//	2019.03.08
//
//	[Ž�� �˰���]
//		<1. ���� Ž��>
//		<2. ���� Ž�� (Interpolation Search)>
//			1) �⺻������ ����Ž���ε�, ù ��° Ž����ġ�� �׳� �߰����� ���� �ʰ�, 
//			   ã�� ���� ���� Ȯ���� ���� ��ġ�� ���� �ٻ�ġ�� ������� ������� �����Ͽ� �����ϴ� ��
//			2) �������� ���� �� �����Ͱ� ����� ��ġ�� �ε��� ���� ����Ѵٰ� ����
//			3) ã�� �����Ͱ��� x��� �� ��, x�� idx = (((x - arr[low]) / (arr[high] - arr[low])) * (high - low)) + low
//

#include <iostream>
using namespace std;

int InterpolationSearch(int arr[], int first, int last, int target)
{
	int mid;
	if (first > last)
		return -1;

	else
	{
		mid = ((double)((target - arr[first]) / (arr[last] - arr[first])) * (last - first)) + first;
		if (arr[mid] == target)
			return mid;
		else if (arr[mid] > target)
			return InterpolationSearch(arr, first, mid - 1, target);
		else
			return InterpolationSearch(arr, mid + 1, last, target);
	}
}

int main(void)
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int idx = 0;

	cout << "Array : ";
	for (int i = 0; i < 10; ++i)
		cout << arr[i] << ' ';
	cout << endl << endl;

	cout << "Search 3" << endl<<endl;

	cout << "==========Interpolation Search==========" << endl << endl;
	idx = InterpolationSearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 3);
	if (idx == -1)
		cout << endl<<"There is no 3." << endl << endl;
	else
		cout << "3 is in [ " << idx << " ]" << endl << endl;

	return 0;
}