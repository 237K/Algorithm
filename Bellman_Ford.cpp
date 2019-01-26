//
//	OS Windows
//	2019.01.26
//
//	[Algorithm]
//		<Bellman-Ford>
//
//	BAEKJOON #11657 Ÿ�Ӹӽ�
//
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <time.h>
using namespace std;

bool Pair_Less(pair<int, int> p1, pair<int, int> p2)						//vector sort()�� �� pair.first�� �������� �����ϱ� ���� Predicate ����
{
	return p1.first > p2.first ? true : false;
}

class Graph
{
private:
	int Node;
	vector<pair<int, int>> *BFG;
	vector<int> Distance;
	bool *Check;
	stack<int> Stack;
public:
	const static int INIT_NODE = 9999999;
	const static int MAX_CITY = 500;
	const static int MAX_EDGE = 6000;
public:
	Graph(int _Node) : Node(_Node)
	{
		BFG = new vector<pair<int, int>>[_Node + 1];
		Check = new bool[_Node + 1];
		Distance.resize(_Node + 1, INIT_NODE);
		Distance[0] = 0;
		for (int i = 0; i < _Node + 1; ++i)
		{
			BFG[i].clear();
			Check[i] = false;
		}
	}
	~Graph()
	{
		delete[] BFG;
		delete[] Check;
	}
	void AddEdge(int _Start, int _End, int _Weight)
	{
		BFG[_Start].push_back(pair<int, int>(_End, _Weight));
		sort(BFG[_Start].begin(), BFG[_Start].end(), Pair_Less);
	}
	void BF(int _Start)
	{
		cout << "�湮 ���� : ";
		Distance[_Start] = 0;
		Stack.push(_Start);
		Check[_Start] = true;
		
		while (!Stack.empty())
		{
			int Current_Node = Stack.top();
			Stack.pop();
			cout<<Current_Node << ' ';

			for (int i = 0; i < BFG[Current_Node].size(); ++i)
			{
				int Next_Node = BFG[Current_Node][i].first;
				if (!Check[Next_Node])
				{
					if(Distance[Next_Node] > Distance[Current_Node] + BFG[Current_Node][i].second)
					{
						Distance[Next_Node] = Distance[Current_Node] + BFG[Current_Node][i].second;
					}
					Stack.push(Current_Node);
					Stack.push(Next_Node);
					Check[Next_Node] = true;
				}
			}
		}
		cout << endl;
	}
	void PrintDistance() const
	{
		for (int i = 2; i < Distance.size(); ++i)
		{
			cout << "1�� ���ÿ��� " << i << "�� ���÷� ���� �ִܰ�� : " << Distance[i] << endl;
		}
	}
};

int main(void)
{
	int NumOfNode, NumOfEdge;
	int Start_Node, End_Node, Weight;
	int Start_Vertex;
	clock_t timer_start, timer_end;
	double timer;

	timer_start = clock();

	ifstream in("TestCase_BellmanFord1.txt");
	if (!in.is_open())
		cout << "������ ã�� �� �����ϴ�." << endl;

	in >> NumOfNode >> NumOfEdge;
	Graph graph(NumOfNode);
	for (int i = 1; i <= NumOfEdge; ++i)
	{
		in >> Start_Node >> End_Node >> Weight;
		graph.AddEdge(Start_Node, End_Node, Weight);
	}
	graph.BF(1);
	graph.PrintDistance();

	in.close();

	timer_end = clock();
	timer = (double)(timer_end - timer_start);
	cout << "Execution Time : " << timer << "ms" << endl;

	return 0;
}