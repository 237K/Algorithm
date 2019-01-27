//
//	OS Windows
//	2019.01.27
//
//	[Algorithm]
//		<다익스트라 Dijkstra>
//
//	SAMSUNG SW Expert Academy #Visual Reference Code <Dijkstra>
//	BAEKJOON #1753
//	
//	우선순위큐를 이용해 구현
//

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <time.h>
using namespace std;


class Vertex_Less : public binary_function<pair<int, int>, pair<int, int>, bool>
{
public:
	bool operator() (const pair<int, int>& pair1, const pair<int, int>& pair2)
	{
		return pair1.second < pair2.second;
	}
};


class Graph
{
private:
	int Node;
	vector<pair<int, int>> *DG;
	vector<int> Distance;
	bool *Check;
	priority_queue<pair<int, int>, vector<pair<int, int>>, Vertex_Less> PQ;
private:
	const static int INF = 2137000000;
public:
	Graph(int _Node) : Node(_Node)
	{
		DG = new vector<pair<int, int>> [_Node + 1];
		Check = new bool [_Node + 1];
		
		for (int i = 0; i < _Node + 1; ++i)
		{
			DG[i].clear();
			Distance[i] = INF;
			Check[i] = false;
		}
	}
	~Graph()
	{
		delete[] DG;
		delete[] Check;
	}
	void AddEdge(int _Start, int _End, int _Weight)
	{
		DG[_Start].push_back(pair<int, int>(_End, _Weight));
		sort(DG[_Start].begin(), DG[_Start].end(), Vertex_Less());
	}
	void Dijkstra(int _Start)
	{
		Distance[_Start] = 0;															//출발노드에서 출발노드까지의 거리는 0으로 갱신
		for(vector<pair<int, int>>::iterator iter = DG[_Start].begin() ; iter != DG[_Start].end(); ++iter)	//우선순위큐(heap구조) 안에서는 가중치가 제일 작은게 top으로 옴
		{
			PQ.push(*iter);																//일단 출발노드에 들어있는 간선정보를 우선순위큐에 다 넣음
			Distance[iter->first] = iter->second;										//DG[출발노드] 안에 들어있는 간선정보는 일단 Distance[도착노드]에 저장
		}
		while (!PQ.empty())																//우선순위큐가 빌 때까지 반복
		{
			int Current_Node = PQ.top().first;											//우선순위큐 top에는 pair<도착노드, 가중치>가 들어있음
			int Current_Node_Weight = PQ.top().second;									//각각 임시변수에 저장하고
			PQ.pop();																	//우선순위큐에서 pop
			if (!Check[Current_Node])													//이 노드를 방문한 적이 없으면,
			{
				Check[Current_Node] = true;												//이 노드 Check를 true로 바꾸고
				if (DG[Current_Node].size() >= 1)
				{
					for (vector<pair<int, int>>::iterator iter = DG[Current_Node].begin(); iter != DG[Current_Node].end(); ++iter)		//이 노드 벡터를 돌면서
					{
						PQ.push(*iter);														//우선순위큐에 현재노드벡터에 들어있는 간선정보를 우선순위큐에 넣음
						//시작노드에서 현재노드(경유노드)까지의 거리가 무한대가 아니고, 현재 시작노드에서 도착노드까지의 거리가 시작노드에서 경유노드를 거쳐 도착노드로 가는 것보다 크면 갱신
						if (Distance[Current_Node] != INF && Distance[iter->first] > Distance[Current_Node] + iter->second)
						{
							Distance[iter->first] = Distance[Current_Node] + iter->second;
						}
					}
				}
				else continue;
			}
		}
		PrintDijkstra(_Start);
	}
	void PrintDijkstra(const int _Start) const
	{
		for (int i = 1; i <= Node; ++i)
		{
			if (Distance[i] != INF)
				cout << _Start<<" 번 노드에서 " << i << "번 노드로 가는 최단 경로 : " << Distance[i] << endl;
			if (Distance[i] == INF)
				cout << _Start<<" 번 노드에서 " << i << "번 노드로 가는 최단 경로는 없습니다 (INF)" << endl;
		}
	}
};

int main(void)
{
	int NumOfNode, NumOfEdge;
	int Start, End, Weight;
	int Start_Vertex;
	clock_t timer_start, timer_end;
	double timer;

	timer_start = clock();
	
	ifstream in("testcase_Dijkstra1.txt");
	if (!in.is_open())
		cout << "파일을 찾을 수 없습니다." << endl;

	in >> NumOfNode >> NumOfEdge;
	in >> Start_Vertex;
	Graph graph(NumOfNode);

	for (int i = 1; i <= NumOfEdge; ++i)
	{
		in >> Start >> End >> Weight;
		graph.AddEdge(Start, End, Weight);
	}

	graph.Dijkstra(Start_Vertex);

	in.close();

	timer_end = clock();
	timer = (double)(timer_end - timer_start);
	cout << "Execution Time : " << timer << "ms" << endl;

	return 0;
}