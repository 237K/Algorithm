//
//	OS Windows
//	2019.01.27
//
//	[Algorithm]
//		<���ͽ�Ʈ�� Dijkstra>
//
//	SAMSUNG SW Expert Academy #Visual Reference Code <Dijkstra>
//	BAEKJOON #1753
//	
//	�켱����ť�� �̿��� ����
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
		Distance[_Start] = 0;															//��߳�忡�� ��߳������� �Ÿ��� 0���� ����
		for(vector<pair<int, int>>::iterator iter = DG[_Start].begin() ; iter != DG[_Start].end(); ++iter)	//�켱����ť(heap����) �ȿ����� ����ġ�� ���� ������ top���� ��
		{
			PQ.push(*iter);																//�ϴ� ��߳�忡 ����ִ� ���������� �켱����ť�� �� ����
			Distance[iter->first] = iter->second;										//DG[��߳��] �ȿ� ����ִ� ���������� �ϴ� Distance[�������]�� ����
		}
		while (!PQ.empty())																//�켱����ť�� �� ������ �ݺ�
		{
			int Current_Node = PQ.top().first;											//�켱����ť top���� pair<�������, ����ġ>�� �������
			int Current_Node_Weight = PQ.top().second;									//���� �ӽú����� �����ϰ�
			PQ.pop();																	//�켱����ť���� pop
			if (!Check[Current_Node])													//�� ��带 �湮�� ���� ������,
			{
				Check[Current_Node] = true;												//�� ��� Check�� true�� �ٲٰ�
				if (DG[Current_Node].size() >= 1)
				{
					for (vector<pair<int, int>>::iterator iter = DG[Current_Node].begin(); iter != DG[Current_Node].end(); ++iter)		//�� ��� ���͸� ���鼭
					{
						PQ.push(*iter);														//�켱����ť�� �����庤�Ϳ� ����ִ� ���������� �켱����ť�� ����
						//���۳�忡�� ������(�������)������ �Ÿ��� ���Ѵ밡 �ƴϰ�, ���� ���۳�忡�� ������������ �Ÿ��� ���۳�忡�� ������带 ���� �������� ���� �ͺ��� ũ�� ����
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
				cout << _Start<<" �� ��忡�� " << i << "�� ���� ���� �ִ� ��� : " << Distance[i] << endl;
			if (Distance[i] == INF)
				cout << _Start<<" �� ��忡�� " << i << "�� ���� ���� �ִ� ��δ� �����ϴ� (INF)" << endl;
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
		cout << "������ ã�� �� �����ϴ�." << endl;

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