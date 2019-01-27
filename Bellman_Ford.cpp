//
//	OS Windows
//	2019.01.26
//
//	[Algorithm]
//		<Bellman-Ford>
//
//	BAEKJOON #11657 타임머신
//

#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

class Graph
{
private:
	int Node;
	int Edge;
	int **BFG;
	int *Distance;
	bool MinusCycle;
public:
	const static int INIT_NODE = 2147000000;
	const static int MAX_CITY = 500;
	const static int MAX_EDGE = 6000;
public:
	Graph(int _Node) : Node(_Node)
	{
		BFG = new int*[_Node + 1];
		for (int i = 0; i < _Node + 1; ++i)
		{
			BFG[i] = new int[_Node + 1];
		}
		Distance = new int[_Node + 1];

		for (int i = 1; i < _Node + 1; ++i)
		{
			Distance[i] = INIT_NODE;
			for (int j = 1; j < _Node + 1; ++j)
			{
				BFG[i][j] = 0;
			}
		}
		MinusCycle = false;
	}
	~Graph()
	{
		for (int i = 0; i < Node + 1; ++i)
		{
			delete[] BFG[i];
		}
		delete[] Distance;
	}
	void AddEdge(int _Start, int _End, int _Weight)
	{
		BFG[_Start][_End] = _Weight;
	}
	void PrintGraph() const
	{
		cout << "=====그래프 출력=====" << endl<<endl;
		for (int i = 1; i <= Node; ++i)
		{
			for (int j = 1; j <= Node; ++j)
			{
				cout << BFG[i][j] << ' ';
			}
			cout << endl;
		}
	}

	void BF(int _Start)
	{
		Distance[_Start] = 0;
		for (int i = 1; i <= Node; ++i)
		{
			for (int j = 1; j <= Node; ++j)
			{
				if (BFG[i][j] != 0 && Distance[j] > Distance[i] + BFG[i][j])
				{
					Distance[j] = Distance[i] + BFG[i][j];
					if (i == Node)
						MinusCycle = true;
				}
			}
		}
		PrintResult();
	}

	void PrintResult() const
	{
		if (MinusCycle)
			cout << "-1" << endl;
		if(!MinusCycle)
		{
			for (int i = 2; i <= Node; ++i)
			{
				if (Distance[i] != INIT_NODE)
					cout << "1에서 출발하여 " << i << "로 가는 최단경로는 " << Distance[i] << " 입니다." << endl;
				if (Distance[i] == INIT_NODE)
					cout << "1에서 출발하여 " << i << "로 가는 경로는 없습니다." << endl;
			}
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

	ifstream in("TestCase_BellmanFord3.txt");

	if (!in.is_open())
		cout << "파일을 찾을 수 없습니다." << endl;

	in >> NumOfNode >> NumOfEdge;
	Graph graph(NumOfNode);
	for (int e = 1; e <= NumOfEdge; ++e)
	{
		in >> Start_Node >> End_Node >> Weight;
		graph.AddEdge(Start_Node, End_Node, Weight);
	}

	graph.PrintGraph();

	graph.BF(1);

	in.close();

	timer_end = clock();
	timer = (double)(timer_end - timer_start);
	cout << "Execution Time : " << timer << "ms" << endl;

	return 0;
}