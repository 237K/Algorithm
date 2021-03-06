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


#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <time.h>
using namespace std;

class Graph_Adjacent_Array
{
private:
	const int GAA_Node_Num;
	const int GAA_Edge_Num;
	int **GAA_Array;
public:
	//생성자
	explicit Graph_Adjacent_Array(const int _Node_Num, const int _Edge_Num) : GAA_Node_Num(_Node_Num), GAA_Edge_Num(_Edge_Num)
	{
		GAA_Array = new int* [_Node_Num + 1];						//행 동적 할당
		for (int i = 1; i <= _Node_Num; ++i)
			GAA_Array[i] = new int [_Node_Num + 1];					//각 행 마다 열 동적 할당

		for (int i = 1; i <= _Node_Num; ++i)						
		{
			for (int j = 1; j <= _Node_Num; ++j)
			{
				GAA_Array[i][j] = 0;								//배열 0으로 초기화
			}
		}
	}
	
	Graph_Adjacent_Array() : GAA_Node_Num(0), GAA_Edge_Num(0) {}	//그래프 객체배열[0] 때문에 정의해둠

	//소멸자
	~Graph_Adjacent_Array()
	{
		for (int d = 1; d <= GAA_Node_Num; ++d)						//각 행마다 열 할당 해제
		{
			delete[] GAA_Array[d];
		}
		delete[] GAA_Array;											//행 할당 해제
	}

	//Edge(간선) 추가
	void AddEdge(int Start, int End)
	{
		GAA_Array[Start][End] = 1;
		GAA_Array[End][Start] = 1;
	}

	void ViewAdjacentNode(int _Node) const
	{
		for (int i = 1; i <= GAA_Node_Num; ++i)
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
		for (int i = 1; i <= GAA_Node_Num; ++i)
		{
			cout << i << "의 인접 노드 : ";
			ViewAdjacentNode(i);
		}
		cout << endl;
	}
	void ViewGAA() const
	{
		cout << "=====인접 행렬=====" << endl;
		for (int i = 1; i <= GAA_Node_Num; ++i)
		{
			for (int j = 1; j <= GAA_Node_Num; ++j)
			{
				cout << GAA_Array[i][j] << ' ';
			}
			cout << endl;
		}
	}
};

int main(void)
{
	clock_t timer_start, timer_end;
	double ExecutionTime;
	int test_case;
	int NumberOfNode;
	int NumberOfEdge;
	int start_buffer, end_buffer;

	timer_start = clock();
	ifstream in("TestCase_graph1.txt");

	if (!in.is_open())
		cout << "파일을 찾을 수 없습니다." << endl;

	//scanf("%d", &test_case);
	in >> test_case;
	//cout << "Test Case 개수 : ";
	//cin >> test_case;
	Graph_Adjacent_Array *Graph[100];														//각 테스트 케이스마다 그래프가 필요하니 객체배열 생성

	for (int t = 1; t <= test_case; ++t)
	{
		//scanf("%d %d", &NumberOfNode, &NumberOfEdge);
		try
		{
		//cout << "노드 개수, 간선 개수 : ";
		//cin >> NumberOfNode >> NumberOfEdge;
		in >> NumberOfNode >> NumberOfEdge;

			if (NumberOfNode <= 1 || NumberOfEdge <= 0)										//Exception Handling
				throw pair<int, int>(NumberOfNode, NumberOfEdge);

			Graph[t] = new Graph_Adjacent_Array(NumberOfNode, NumberOfEdge);				//graph 객체 생성 -> 생성자 호출 -> 초기화 완료

			for (int e = 1; e <= NumberOfEdge; ++e)
			{
				//scanf("%d %d", &start_buffer, &end_buffer);
				try
				{
				//cout << "시작 노드, 타겟 노드 : ";
				//cin >> start_buffer >> end_buffer;
				in >> start_buffer >> end_buffer;

				if (start_buffer <= 0 || end_buffer <= 0)									//Exception Handling
					throw pair<int, int>(start_buffer, end_buffer);

				Graph[t]->AddEdge(start_buffer, end_buffer);								//간선 추가 함수(AddEdge) 호출 
				}
				catch (pair<int, int> expn2)
				{
					cout << "(error) 간선 추가 실패" << endl;
					cout << "error message : " << "출발노드 : " << expn2.first << "타겟노드 : " << expn2.second << endl;
				}
			}
		}
		catch (pair<int, int> expn)
		{
			cout << "#" << t << "(error) graph 생성 실패" << endl;
			cout << "error message : 입력받은 노드 수 : " << expn.first << " / 입력받은 간선 수 : " << expn.second << endl;
		}
	}

	for (int t = 1; t <= test_case; ++t)
	{
		cout << "#" << t << endl;
		Graph[t]->ViewGAA();
		Graph[t]->ViewAdjacentNode();
	}

	for (int t = 1; t <= test_case; ++t)
	{
		delete Graph[t];
	}

	in.close();
	
	timer_end = clock();
	ExecutionTime = (double)(timer_end - timer_start);
	cout << endl << "Execution Time : " << ExecutionTime <<"ms"<< endl;

	return 0;
}
