//
//	OS Windows
//	2019.01.25
//
//	[Algorithm]
//		<DFS>
//			1. Recursion(재귀) 이용
//			2. stack 이용
//
//	1. 재귀 이용
//
//	BAEKJOON #1260 (https://www.acmicpc.net/problem/1260)
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

class Graph
{
private:
	const int Node_Num;
	const int Edge_Num;
	vector<int> *GV;
	bool *Check;
public:
	Graph(int _Node, int _Edge) : Node_Num(_Node), Edge_Num(_Edge)
	{
		cout << "call constructor" << endl;
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
		cout << "call destructor" << endl;
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
	void DFS(int _Vertex)
	{
		Check[_Vertex] = true;
		cout << _Vertex << " -> ";
		for (int i = 0; i < GV[_Vertex].size(); ++i)
		{
			int Next_Vertex = GV[_Vertex][i];
			if (!Check[Next_Vertex])
				DFS(Next_Vertex);
		}
		cout << "DFS End" << endl;
	}
};

int main(void)
{
	int NumOfNode;
	int NumOfEdge;
	int Start_Node, End_Node;
	int Start_Vertex;
	clock_t timer_start, timer_end;
	double timer;

	timer_start = clock();

	ifstream in("TestCase_DFS1.txt");

	if (!in.is_open())
		cout << "파일을 찾을 수 없습니다." << endl;

	in >> NumOfNode >> NumOfEdge >> Start_Vertex;
	Graph graph(NumOfNode, NumOfEdge);

	for (int e = 1; e <= NumOfEdge; ++e)
	{
		in >> Start_Node >> End_Node;
		graph.AddEdge(Start_Node, End_Node);
	}

	graph.DFS(Start_Vertex);

	in.close();

	timer_end = clock();
	timer = (double)(timer_end - timer_start);
	cout << "Execution Time : " << timer << "ms" << endl;

	return 0;
}