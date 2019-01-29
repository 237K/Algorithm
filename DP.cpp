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
	vector<int> *DP;			//Ǯ�̰��� �����
	vector<int> *Board;			//��ǲ�� �����
	const int Width;			//���� ���� ��ǲ��
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
	void AddSticker(ifstream& _in)					//ostream& �޾ƿͼ� �����ڿ����ε��ϴ� ��ó�� ifstream& �޾ƿͼ� �Է¹ް� �غôµ� �ǳ�
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
		cout << endl << "=====��� �Ϸ�(���� ��)=====" << endl << endl;
		PrintBoard();
		
		for (int i = 0; i < MAX_LENGTH; ++i)			
		{
			sort(DP[i].begin(), DP[i].end());					//�� ���� ��������(less) ����. �� �������� ���ص� �������� �ѵ�, Ȥ�ó� ���� ���� �־��� ��츦 ����ؼ�
		}
		cout << endl << "=====���� ��=====" << endl << endl;
		PrintBoard();
		Result = max(DP[0][Width - 1], DP[1][Width - 1]);		//���� ū ���� �� ���� ������ ���Ҹ� ���غ��� ��

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
		cout << "������ ã�� �� �����ϴ�." << endl;

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