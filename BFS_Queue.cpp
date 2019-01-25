//
//	OS Windows
//	2019.01.26
//
//	[Algorithm]
//		<BFS>
//			1. Queue 이용
//
//	BAEKJOON #1260 (https://www.acmicpc.net/problem/1260)
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <time.h>
using namespace std;

class Graph
{
private:
	const int Node, Edge;
	vector<int> *GV;
	queue<int> Q;
	bool *Check;
public:
	Graph(const int _Node, const int _Edge) : Node(_Node), Edge(_Edge)
	{
		GV = new vector<int>[_Node + 1];
		Check = new bool[_Node + 1];

		for (int i = 0; i < _Node + 1; ++i)
		{
			GV[i].clear();
			Check[i] = false;
		}
	}
	~Graph()
	{
		delete[] GV;
		delete[] Check;
	}
	void AddEdge(int _Start, int _End)
	{
		GV[_Start].push_back(_End);
		GV[_End].push_back(_Start);

		sort(GV[_Start].begin(), GV[_Start].end());
		sort(GV[_End].begin(), GV[_End].end());
	}
	void BFS(int _Start_Vertex)
	{
		Q.push(_Start_Vertex);
		Check[_Start_Vertex] = true;

		while (!Q.empty())
		{
			int Current_Node = Q.front();
			Q.pop();
			cout << Current_Node << ' ';

			for (vector<int>::size_type i = 0; i < GV[Current_Node].size(); ++i)
			{
				if (!Check[Current_Node])
				{
					Q.push(GV[Current_Node][i]);
					Check[Current_Node] = true;
				}
			}
		}
		cout << "BFS End" << endl;
	}
};

int main(void)
{
	int NumOfNode, NumOfEdge;
	int Start_Vertex;
	int Start_Node, End_Node;
	clock_t timer_start, timer_end;
	double timer;

	timer_start = clock();

	ifstream in("TestCase_DFS1.txt");

	if (!in.is_open())
		cout << "파일을 찾을 수 없습니다." << endl;

	in >> NumOfNode >> NumOfEdge >> Start_Vertex;
	Graph graph(NumOfNode, NumOfEdge);
	for (int i = 1; i <= NumOfEdge; ++i)
	{
		in >> Start_Node >> End_Node;
		graph.AddEdge(Start_Node, End_Node);
	}

	graph.BFS(Start_Vertex);

	in.close();

	return 0;
}