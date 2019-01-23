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

#include <iostream>
#include <fstream>
#include <cstio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Graph_Adjacent_Array
{
private:
	const int GAA_Node_Num;
	const int GAA_Edge_Num;
	int **GAA_Array;
public:
	//생성자
	explicit Graph_Adjacent_Array(int _Node_Num, int _Edge_Num) : GAA_Node_Num(_Node_Num), GAA_Edge_Num(_Edge_Num)
	{
		try
		{
			if (_Node_Num <= 0 || _Edge_Num <= 0)					//Exception Handling
				throw pair<int, int>(_Node_Num, _Edge_Num);

			GAA_Array = new int *[_Node_Num];						//행 동적 할당
			for (int i = 0; i < _Node_Num; ++i)
			{
				GAA_Array[i] = new int[_Node_Num];					//각 행 마다 열 동적 할당
				memset(GAA_Array[i], 0, sizeof(int)*_Node_Num);		//배열 초기화
			}
		}
		catch (pair<int, int> expn)
		{
			cout << "(error) graph 생성 실패" << endl;
			cout << "error message : 입력받은 노드 수 : " << expn.first << " / 입력받은 간선 수 : " << expn.second << endl;
		}
	}
	
	//소멸자
	~Graph_Adjacent_Array()
	{
		for (int i = 0; i < GAA_Node_Num; ++i)
		{
			delete[] GAA_Array[i];
		}
		delete[] GAA_Array;
	}

	//Edge(간선) 추가
	void AddEdge(int Start, int End)
	{
		try
		{
			if (Start <= 0 || End <= 0)								//Exception Handling
				throw Start;

			GAA_Array[Start][End] = 1;
			GAA_Array[End][Start] = 1;
		}
		catch (int expn)
		{
			cout << "(error) 간선 추가 실패" << endl;
			cout << "error message : 출발 노드 혹은 타겟 노드 값이 0이하 입니다." << endl;
		}
	}
	void ViewAdjacentNode(int _Node) const
	{
		for (int i = 0; i < GAA_Node_Num; ++i)
		{
			if (GAA_Array[_Node][i] != 0)
			{
				cout << i << " ";
			}
		}
		cout << endl;
	}
	void ViewAdjacentNode() const
	{
		cout << "=====인접 노드=====" << endl;
		for (int i = 0; i < GAA_Node_Num; ++i)
		{
			cout << i << "의 인접 노드 : ";
			ViewAdjacentNode(i);
		}
		cout << endl;
	}
	void ViewGAA() const
	{
		for (int i = 0; i < GAA_Node_Num; ++i)
		{
			for (int j = 0; j < GAA_Node_Num; ++j)
			{
				cout << GAA_Array[i][j] << ' ';
			}
			cout << endl;
		}
	}
};

int main(void)
{
	ifstream in("TestCase_graph1")
}
