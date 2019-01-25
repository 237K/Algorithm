//
//	OS Windows
//	2019.01.23
//
//	[Algorithm]
//		<Graph>
//			1) 인접행렬 방식 : int** / int adjacent_array[][] / 간선의 개수가 적은 경우 비효율적일 수 있음
//				
//					│	1	│	2	│	3	|	4	|	5	|
//			   ──────────────────────────────────────────────
//				 1  │	0	|	1	|	1	|	0	|	0	|
//			   ──────────────────────────────────────────────		
//				 2  │	0	|	0	|	1	|	1	|	1	|
//			   ──────────────────────────────────────────────
//				 3  │	0	|	0	|	0	|	1	|	1	|
//			   ──────────────────────────────────────────────
//				 4  │	0	|	0	|	0	|	0	|	1	|
//			   ──────────────────────────────────────────────
//				 5  │	0	|	0	|	0	|	0	|	0	|
//			   ──────────────────────────────────────────────
//
//			2) 인접리스트 방식 : vector<int> adjacent[] / 실제로 연결된 노드들에 대한 정보만 저장하므로 간선의 개수에 비례하는 메모리만 차지. 노드가 연결되었는지 확인하는 경우 비효율적일 수 있음
//
//			   ───────   ───────────────			
//			  |   1   |	|	2	|	3	|
//			   ───────   ───────────────────────
//			  |   2   |	|	3	|	4	|	5	|
//			   ───────   ───────────────────────
//			  |   3   |	|	4	|	5	|
//			   ───────   ───────────────
//			  |   4   |	|	5	|
//			   ───────   ───────
//			  |   5   |
//			   ───────
//
//	2) 인접리스트 방식으로 구현
//		- 가중치 주려면 pair로 하면 됨
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

class Graph_Adjacent_List
{
private:
	vector<pair<int, int>> *GAL_Vector;
	const int Node_Num;
	const int Edge_Num;
	int Weight;
public:
	//생성자
	explicit Graph_Adjacent_List(const int _Node_Num, const int _Edge_Num) : Node_Num(_Node_Num), Edge_Num(_Edge_Num), Weight(0)
	{
		GAL_Vector = new vector<pair<int, int>>[_Node_Num + 1];
		
		for (int init = 0; init <= _Node_Num; ++init)
		{
			GAL_Vector[init].clear();
		}
		cout << "call constructor" << endl;
	}

	Graph_Adjacent_List() :Node_Num(0), Edge_Num(0), Weight(0) {}

	//소멸자
	~Graph_Adjacent_List()
	{
		cout << "call destructor" << endl;
		delete[] GAL_Vector;
	}

	//간선 추가
	void AddEdge(int _Start, int _End, int _Weight = 1)
	{
		cout << "call AddEdge" << endl;
		GAL_Vector[_Start].push_back(pair<int, int> (_End, _Weight));
		GAL_Vector[_End].push_back(pair<int, int> (_Start, _Weight));
		
		sort(GAL_Vector[_Start].begin(), GAL_Vector[_Start].end());							//less로 정렬
		sort(GAL_Vector[_End].begin(), GAL_Vector[_End].end());
	}

	//인접 노드 출력
	void ViewAdjacentNode() const															//노드를 출력하는 함수
	{																						//노드 내부를 출력하기 위한 함수는 따로 구현하여 호출
		try
		{
			if (Node_Num <= 1)
				throw Node_Num;

			for (int VAN = 1; VAN <= Node_Num; ++VAN)
			{
				cout << VAN << "의 인접노드 : ";
				ViewAdjacentNode(GAL_Vector[VAN]);												//함수 내에서 오버로딩된 ViewAdjacentNode 함수를 호출
			}
			cout << endl;
		}
		catch (const int expn)
		{
			cout << "error" << endl << "error message  Node는 1개 이하일 수 없습니다. 입력받은 Node의 개수 : " << expn << endl;
		}
	}

	void ViewAdjacentNode(const vector<pair<int, int>>& _GAL) const							//각 노드의 내부를 출력하기 위한 함수
	{
		for (vector<pair<int, int>>::size_type i = 0; i < _GAL.size(); ++i)
		{
			cout << "(" << _GAL[i].first << ", " << _GAL[i].second << ") ";
		}
		cout << endl;
	}
};

int main(void)
{
	clock_t timer_start, timer_end;
	double ExecutionTime;
	int test_case;
	int NumOfNode;
	int NumOfEdge;
	int EdgeWeight;
	int Start_Buffer, End_Buffer;
	Graph_Adjacent_List *Graph[100];

	timer_start = clock();

	ifstream in("TestCase_graph1.txt");

	if (!in.is_open())
		cout << "파일을 찾을 수 없습니다." << endl;

	in >> test_case;
	for (int tc = 1; tc <= test_case; ++tc)
	{
		try
		{
			in >> NumOfNode >> NumOfEdge;

			if (NumOfNode <= 1 || NumOfEdge <= 0)
				throw pair<int, int>(NumOfNode, NumOfEdge);

			Graph[tc] = new Graph_Adjacent_List(NumOfNode, NumOfEdge);

			for (int e = 1; e <= NumOfEdge; ++e)
			{
				try
				{
					in >> Start_Buffer >> End_Buffer;

					if (Start_Buffer <= 0 || End_Buffer <= 0 || Start_Buffer == End_Buffer)
						throw pair<int, int>(Start_Buffer, End_Buffer);

					Graph[tc]->AddEdge(Start_Buffer, End_Buffer, 1);
				}
				catch (pair<int, int> Edge_Expn)
				{
					cout << "error" << endl << "error message  Start Node : " << Edge_Expn.first << " End Node : " << Edge_Expn.second << endl;
				}
			}
		}
		catch (pair<int, int> Node_Expn)
		{
			cout << "error" << endl << "error message  Number of Node : " << Node_Expn.first << " Number of Edge : " << Node_Expn.second << endl;
			return 0;
		}
	}
	for (int tc = 1; tc <= test_case; ++tc)
	{
		cout << "#" << tc << endl;
		Graph[tc]->ViewAdjacentNode();
	}

	for (int del = 1; del <= test_case; ++del)
	{
		delete Graph[del];
	}

	in.close();

	timer_end = clock();
	ExecutionTime = (double)(timer_end - timer_start);
	cout << endl << "Execution Time : " << ExecutionTime << "ms" << endl;

	return 0;
}