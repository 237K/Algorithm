//
//	OS Windows
//	2019.01.27
//
//	[Algorithm]
//		<DP (Dynamic Programming)>
//
//	SAMSUNG SW Expert Academy #Visual Reference Code <Dynamic Programming>
//	

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

class DynamicProgramming
{
private:
	vector<int> *DP;			//풀이과정 저장소
	vector<int> *Board;			//인풋값 저장소
	const int Width;			//가로 길이 인풋값
	int Sticker;
	int Result;					
public:
	const static int MAX_LENGTH = 2;
	const static int MAX_WIDTH = 100001;
public:
	explicit DynamicProgramming(const int _Width) : Width(_Width), Result(0), Sticker(0)
	{
		DP = new vector<int> [MAX_LENGTH];
		Board = new vector<int> [MAX_LENGTH];
		for (int i = 0; i < MAX_LENGTH; ++i)
		{
			DP[i].clear();
			Board[i].clear();
		}
	}
	~DynamicProgramming()
	{
		delete[] DP;
		delete[] Board;
	}
	void AddSticker(ifstream& _in)					//ostream& 받아와서 연산자오버로딩하는 것처럼 ifstream& 받아와서 입력받게 해봤는데 되네
	{
		for (int i = 0; i < MAX_LENGTH; ++i)
		{
			for (int j = 0; j < Width; ++j)
			{
				_in >> Sticker;
				Board[i].push_back(Sticker);
			}
		}
	}
	void Solution()
	{
		DP[0].push_back(Board[0][0]);
		DP[1].push_back(Board[1][0]);
		DP[0].push_back(Board[0][1] + Board[1][0]);
		DP[1].push_back(Board[1][1] + Board[0][0]);
		
		for (int i = 2; i < Width; ++i)
		{
			DP[0].push_back(Board[0][i] + max(max(DP[0][i - 2], DP[1][i - 2]), DP[1][i - 1]));		//MAX3(DP[0][i - 2], DP[1][i - 2], DP[1][i - 1]);
			DP[1].push_back(Board[1][i] + max(max(DP[0][i - 2], DP[0][i - 1]), DP[1][i - 2]));		//MAX3(DP[0][i - 2], DP[0][i - 1], DP[1][i - 2]);
		}
		cout << endl << "=====계산 완료(정렬 전)=====" << endl << endl;
		PrintBoard();
		
		for (int i = 0; i < MAX_LENGTH; ++i)			
		{
			sort(DP[i].begin(), DP[i].end());					//각 행을 오름차순(less) 정렬. 본 문제에선 안해도 문제없긴 한데, 혹시나 음수 값이 주어질 경우를 대비해서
		}
		cout << endl << "=====정렬 후=====" << endl << endl;
		PrintBoard();
		Result = max(DP[0][Width - 1], DP[1][Width - 1]);		//제일 큰 값은 각 행의 마지막 원소를 비교해보면 됨

		cout << "Answer : " << Result << endl << endl;
	}
	void PrintBoard() const
	{
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
	}
};

int main(void)
{
	DynamicProgramming *dp[10];
	int _Width;
	int testcase;
	int _Sticker;

	clock_t timer_start, timer_end;
	double timer;

	timer_start = clock();

	ifstream in("testcase_DP1.txt");
	if (!in.is_open())
		cout << "파일을 찾을 수 없습니다." << endl;

	in >> testcase;
	for (int tc = 0; tc < testcase; ++tc)
	{
		in >> _Width;
		dp[tc] = new DynamicProgramming(_Width);

		dp[tc]->AddSticker(in);

		cout << endl;
		cout << "#" << tc + 1 << endl;
		dp[tc]->Solution();
	}

	timer_end = clock();
	timer = (double)(timer_end - timer_start);
	cout << "Execution Time : " << timer << "ms" << endl;

	in.close();
	for (int del = 0; del < testcase; ++del)
	{
		delete dp[del];
	}

	return 0;
}