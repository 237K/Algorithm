//
//	OS Windows
//	2019.03.03
//
//	[Å½»ö ¾Ë°í¸®Áò]
//		<1. ÀÌÁø Å½»ö>
//			
//

#include <iostream>
using namespace std;

int BinarySearch(int arr[], int first, int last, int target)
{
	int mid;
	if (first > last)
		return -1;

	else
	{
		mid = (first + last) / 2;

		if (arr[mid] == target)
			return mid;
		else if (arr[mid] > target)
			return BinarySearch(arr, first, mid - 1, target);
		else
			return BinarySearch(arr, mid + 1, last, target);
	}
}

int main(void)
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int idx = 0;

	idx = BinarySearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 3);

	if (idx == -1)
		cout << "There is no 3." << endl << endl;
	else
		cout << "3 is in [" << idx << "]" << endl << endl;

	return 0;
}