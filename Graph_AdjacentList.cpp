//
//	OS Windows
//	2019.01.23
//
//	[Algorithm]
//		<Graph>
//			1) ������� ��� : int** / int adjacent_array[][] / ������ ������ ���� ��� ��ȿ������ �� ����
//				
//					��	1	��	2	��	3	|	4	|	5	|
//			   ��������������������������������������������������������������������������������������������
//				 1  ��	0	|	1	|	1	|	0	|	0	|
//			   ��������������������������������������������������������������������������������������������		
//				 2  ��	0	|	0	|	1	|	1	|	1	|
//			   ��������������������������������������������������������������������������������������������
//				 3  ��	0	|	0	|	0	|	1	|	1	|
//			   ��������������������������������������������������������������������������������������������
//				 4  ��	0	|	0	|	0	|	0	|	1	|
//			   ��������������������������������������������������������������������������������������������
//				 5  ��	0	|	0	|	0	|	0	|	0	|
//			   ��������������������������������������������������������������������������������������������
//
//			2) ��������Ʈ ��� : vector<int> adjacent[] / ������ ����� ���鿡 ���� ������ �����ϹǷ� ������ ������ ����ϴ� �޸𸮸� ����. ��尡 ����Ǿ����� Ȯ���ϴ� ��� ��ȿ������ �� ����
//
//			   ��������������   ������������������������������			
//			  |   1   |	|	2	|	3	|
//			   ��������������   ����������������������������������������������
//			  |   2   |	|	3	|	4	|	5	|
//			   ��������������   ����������������������������������������������
//			  |   3   |	|	4	|	5	|
//			   ��������������   ������������������������������
//			  |   4   |	|	5	|
//			   ��������������   ��������������
//			  |   5   |
//			   ��������������
//
//	2) ��������Ʈ ������� ����
//		- ����ġ �ַ��� pair�� �ϸ� ��
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
	//������
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

	//�Ҹ���
	~Graph_Adjacent_List()
	{
		cout << "call destructor" << endl;
		delete[] GAL_Vector;
	}

	//���� �߰�
	void AddEdge(int _Start, int _End, int _Weight = 1)
	{
		cout << "call AddEdge" << endl;
		GAL_Vector[_Start].push_back(pair<int, int> (_End, _Weight));
		GAL_Vector[_End].push_back(pair<int, int> (_Start, _Weight));
		
		sort(GAL_Vector[_Start].begin(), GAL_Vector[_Start].end());							//less�� ����
		sort(GAL_Vector[_End].begin(), GAL_Vector[_End].end());
	}

	//���� ��� ���
	void ViewAdjacentNode() const															//��带 ����ϴ� �Լ�
	{																						//��� ���θ� ����ϱ� ���� �Լ��� ���� �����Ͽ� ȣ��
		try
		{
			if (Node_Num <= 1)
				throw Node_Num;

			for (int VAN = 1; VAN <= Node_Num; ++VAN)
			{
				cout << VAN << "�� ������� : ";
				ViewAdjacentNode(GAL_Vector[VAN]);												//�Լ� ������ �����ε��� ViewAdjacentNode �Լ��� ȣ��
			}
			cout << endl;
		}
		catch (const int expn)
		{
			cout << "error" << endl << "error message  Node�� 1�� ������ �� �����ϴ�. �Է¹��� Node�� ���� : " << expn << endl;
		}
	}

	void ViewAdjacentNode(const vector<pair<int, int>>& _GAL) const							//�� ����� ���θ� ����ϱ� ���� �Լ�
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
		cout << "������ ã�� �� �����ϴ�." << endl;

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