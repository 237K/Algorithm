//
//	OS Windows
//	2019.01.25
//
//	[Algorithm]
//		<DFS>
//			1. Recursion(재귀) 이용
//			2. stack 이용
//
//	2. stack 이용
//
//	BAEKJOON #1260 (https://www.acmicpc.net/problem/1260)
//

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
#include <time.h>
using namespace std;

class Graph
{
private:
	const int Node_Num;
	const int Edge_Num;
	vector<int> *GV;
	stack<int> Stack;
	bool *Check;
public:
	Graph(const int _Node_Num, const int _Edge_Num) : Node_Num(_Node_Num), Edge_Num(_Edge_Num)
	{
		GV = new vector<int>[_Node_Num + 1];
		Check = new bool[_Node_Num + 1];

		for (int i = 0; i < _Node_Num + 1; ++i)
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
	void DFS(int _Start_Vertex)
	{
		Stack.push(_Start_Vertex);
		Check[_Start_Vertex] = true;
		cout << _Start_Vertex << " ";
		while(!Stack.empty())
		{
			int Recent_Node = Stack.top();
			Stack.pop();
			for (vector<int>::size_type i = 0; i < GV[Recent_Node].size(); ++i)
			{
				int Next_Node = GV[Recent_Node][i];
				if (!Check[Next_Node])
				{
					cout << Next_Node << ' ';
					Check[Next_Node] = true;
					Stack.push(Recent_Node);
					Stack.push(Next_Node);
				}
			}
		}
		cout << "DFS(stack) End" << endl;
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

	try
	{
		in >> NumOfNode >> NumOfEdge >> Start_Vertex;
		Graph graph(NumOfNode, NumOfEdge);

		if (NumOfNode <= 1 || NumOfEdge <= 0)
			throw pair<int, int>(NumOfNode, NumOfEdge);

		for (int i = 1; i <= NumOfEdge; ++i)
		{
			in >> Start_Node >> End_Node;

			if (Start_Node == End_Node || Start_Node <= 0 || End_Node <= 0)
				throw pair<int, int>(Start_Node, End_Node);

			graph.AddEdge(Start_Node, End_Node);
		}
		graph.DFS(Start_Vertex);
	}
	catch (pair<int, int> expn)
	{
		cout << "(error) " << expn.first << ", " << expn.second << endl;
	}

	in.close();

	timer_end = clock();
	timer = (double)(timer_end - timer_start);
	cout << "Execution Time : " << timer << "ms" << endl;

	return 0;
}