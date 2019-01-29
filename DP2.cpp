//
//	OS Windows
//	2019.01.28
//
//	[Algorithm]
//		<DP (Dynamic Programming)>
//
//	SAMSUNG SW Expert Academy #Visual Reference Code <Dynamic Programming>
//	

#include <iostream>
#include <fstream>
#include <algorithm>
#include <time.h>
using namespace std;

const static int MAX_LENGTH = 2;
const static int MAX_WIDTH = 100001;

void Less_Sort(int& left, int& right)		//배열 오름차순(less) 정렬을 위한 함수 정의
{											//해당 문제에선 정렬 안해도 되긴한데, 혹시 음수 값 입력받을까봐 정렬함
	int temp;
	if (left > right)
	{
		temp = right;
		right = left;
		left = temp;
	}
}

int main(void)
{
	int **DP;								//풀이과정을 저장하기 위한 2차배열
	int **Board;							//스티커 인풋값을 저장하기 위한 2차배열
	int Width;
	int Result;
	int Sticker;
	int testcase;

	clock_t timer_start, timer_end;
	double timer;

	DP = new int*[MAX_LENGTH];				//행 동적할당
	Board = new int*[MAX_LENGTH];			//행 동적할당

	timer_start = clock();

	ifstream in("testcase_DP1.txt");
	if (!in.is_open())
		cout << "파일을 찾을 수 없습니다." << endl;

	in >> testcase;
	for (int tc = 0; tc < testcase; ++tc)
	{
		in >> Width;
		for (int L = 0; L < MAX_LENGTH; ++L)
		{
			DP[L] = new int[Width];			//열 동적할당
			Board[L] = new int[Width];		//열 동적할당
			for (int W = 0; W < Width; ++W)
			{
				in >> Sticker;				//스티커 입력받아서
				Board[L][W] = Sticker;		//Board에 차곡차곡 넣음
			}
		}

		//알고리즘 시작
		DP[0][0] = Board[0][0];						
		DP[1][0] = Board[1][0];
		DP[0][1] = Board[0][1] + Board[1][0];
		DP[1][1] = Board[1][1] + Board[0][0];

		for (int i = 2; i < Width; ++i)
		{
			DP[0][i] = Board[0][i] + max(max(DP[0][i - 2], DP[1][i - 2]), DP[1][i - 1]);		//MAX3(DP[0][i - 2], DP[1][i - 2], DP[1][i - 1]);
			DP[1][i] = Board[1][i] + max(max(DP[0][i - 2], DP[0][i - 1]), DP[1][i - 2]);		//MAX3(DP[0][i - 2], DP[0][i - 1], DP[1][i - 2]);
		}

		for (int i = 0; i < MAX_LENGTH; ++i)
		{
			for (int j = 0; j < Width - 1 ; ++j)
			{
				Less_Sort(DP[i][j], DP[i][j + 1]);						//해당 문제에선 정렬 안해도 되긴한데, 혹시 음수 값 입력받을까봐 정렬함
			}															//각 행을 정렬하고나서
		}
		for (int i = 0; i < MAX_LENGTH-1; ++i)
		{
			Result = max(DP[i][Width-1], DP[i + 1][Width-1]);			//각 행의 마지막 원소(각 행에서 제일 큰 원소)끼리 비교한다음 큰 값으로 Result 갱신
		}
		cout << "#" << tc + 1 << endl << endl;
		cout << "=====Board=====" << endl << endl;
		for (int i = 0; i < MAX_LENGTH; ++i)
		{
			for (int j = 0; j < Width; ++j)
			{
				cout << Board[i][j] << ' ';
			}
			cout << endl << endl;
		}
		cout << "=====DP=====" << endl << endl;
		for (int i = 0; i < MAX_LENGTH; ++i)
		{
			for (int j = 0; j < Width; ++j)
			{
				cout << DP[i][j] << ' ';
			}
			cout << endl << endl;
		}
		cout << "Answer : " << Result << endl << endl;
	}

	timer_end = clock();
	timer = (double)(timer_end - timer_start);
	cout << "Execution Time : " << timer << "ms" << endl;
	in.close();
	return 0;
}