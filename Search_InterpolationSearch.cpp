//
//	OS Windows
//	2019.03.08
//
//	[탐색 알고리즘]
//		<1. 이진 탐색>
//		<2. 보간 탐색 (Interpolation Search)>
//			1) 기본적으로 이진탐색인데, 첫 번째 탐색위치를 그냥 중간으로 하지 않고, 
//			   찾는 값이 있을 확률이 높은 위치에 대한 근사치를 비례적인 방법으로 추정하여 설정하는 것
//			2) 데이터의 값과 그 데이터가 저장된 위치의 인덱스 값이 비례한다고 가정
//			3) 찾는 데이터값을 x라고 할 때, x의 idx = (((x - arr[low]) / (arr[high] - arr[low])) * (high - low)) + low
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