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
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

bool Pair_Less(pair<int, int> p1, pair<int, int> p2)						//vector sort()할 때 pair.first를 기준으로 정렬하기 위한 Predicate 정의
{
	return p1.first > p2.first ? true : false;
}

class Graph
{
private:
	const int Node;
	vector<pair<int, int>> *BFG;											//pair.first는 도착노드, pair.second는 가중치
	vector<int> Distance;													//도착노드까지의 거리를 저장하는 vector
	bool NegativeCycle;														//음의 사이클 존재여부 확인을 위한 변수
public:
	const static int INIT_NODE = 237000000;
	const static int MAX_CITY = 500;
	const static int MAX_EDGE = 6000;
public:
	Graph(const int _Node) : Node(_Node)
	{
		BFG = new vector<pair<int, int>>[_Node + 1];
		Distance.resize(_Node + 1, INIT_NODE);								//모든 Distance를 무한대로 초기화
		for (int i = 0; i < _Node + 1; ++i)
		{
			BFG[i].clear();
		}
		NegativeCycle = false;
		PrintCurrentDistance();
	}
	~Graph()
	{
		delete[] BFG;
	}
	void AddEdge(int _Start, int _End, int _Weight)							//간선 추가
	{
		BFG[_Start].push_back(pair<int, int>(_End, _Weight));				//방향성 있는 그래프
		sort(BFG[_Start].begin(), BFG[_Start].end(), Pair_Less);			//도착노드를 기준으로 less 정렬
	}
	void BF(int _Start)
	{
		Distance[_Start] = 0;

			for (int i = 1; i <= Node; ++i)																		//N까지 가는 최단경로는 N-1번만 돌아도 결정됨. 음의 사이클 확인을 위해 한번 더 돔
			{
				for (vector<pair<int, int>>::iterator iter = BFG[i].begin(); iter != BFG[i].end(); ++iter)		//각 노드와 연결된 노드들을 순회하다가
				{
					//출발노드에서 지금노드까지 거리가 무한대가 아니고 && 지금노드에서 경유노드까지 가는 거리랑 경유노드에서 도착노드까지 가는 거리를 합쳤을 때, 지금 노드에서 바로 도착노드까지 가는 것보다 작으면 갱신
					if (Distance[i] != INIT_NODE && Distance[iter->first] > (Distance[i] + iter->second))		
					{
						Distance[iter->first] = Distance[i] + iter->second;
						if (i == Node)													//Node가 N개인데, N번째에도 값이 갱신된다는 것은
							NegativeCycle = true;										//도착노드에서 출발노드를 경유하고 다시 도착노드로 가는 시간이 갱신된다는 것이므로 음의 사이클이 존재함
					}
				}
		}
		PrintCurrentDistance();
		PrintDistance();
	}
	void PrintDistance() const
	{
		if (NegativeCycle)
			cout << "음의 사이클이 존재합니다." << endl;
		else
		{
			for (int i = 2; i < Distance.size(); ++i)
			{
				if (Distance[i] != INIT_NODE)
					cout << "1번 도시에서 " << i << "번 도시로 가는 최단경로 : " << Distance[i] << endl;
				if (Distance[i] == INIT_NODE)
					cout << "1번 도시에서 " << i << "번 도시로 가는 최단경로 : -1" << endl;
			}
		}
	}
	void PrintCurrentDistance() const
	{
		for (vector<int>::size_type i = 0; i < Distance.size(); ++i)
		{
			cout << "[" << i << "] " << Distance[i] << endl;
		}
		cout << "is Negative Cycle ? " << NegativeCycle << endl;
		cout << endl;
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

	ifstream in("TestCase_BellmanFord4.txt");
	if (!in.is_open())
		cout << "파일을 찾을 수 없습니다." << endl;

	in >> NumOfNode >> NumOfEdge;
	Graph graph(NumOfNode);
	for (int i = 1; i <= NumOfEdge; ++i)
	{
		in >> Start_Node >> End_Node >> Weight;
		graph.AddEdge(Start_Node, End_Node, Weight);
	}
	graph.BF(1);

	in.close();

	timer_end = clock();
	timer = (double)(timer_end - timer_start);
	cout << "Execution Time : " << timer << "ms" << endl;

	return 0;
}