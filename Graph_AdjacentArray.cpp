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
//	1) ������Ĺ�� �׷��� ����
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
using namespace std;

class Graph_Adjacent_Array
{
private:
	const int GAA_Node_Num;
	const int GAA_Edge_Num;
	int **GAA_Array;
public:
	//������
	explicit Graph_Adjacent_Array(int _Node_Num, int _Edge_Num) : GAA_Node_Num(_Node_Num), GAA_Edge_Num(_Edge_Num)
	{
		GAA_Array = new int* [_Node_Num + 1];						//�� ���� �Ҵ�
		for (int i = 0; i < _Node_Num + 1; ++i)
		{
			GAA_Array[i] = new int[_Node_Num + 1];					//�� �� ���� �� ���� �Ҵ�
			for (int j = 0; j < _Node_Num + 1; ++j)
			{
				GAA_Array[i][j] = 0;								//�迭 �ʱ�ȭ
			}
		}
	}
	
	//�Ҹ���
	~Graph_Adjacent_Array(void)
	{
		for (int i = 0; i < GAA_Node_Num + 1; ++i)
		{
			delete[] GAA_Array[i];
		}
		delete[] GAA_Array;
	}

	//Edge(����) �߰�
	void AddEdge(int Start, int End)
	{
		GAA_Array[Start][End] = 1;
		GAA_Array[End][Start] = 1;
	}

	void ViewAdjacentNode(int _Node) const
	{
		for (int i = 1; i < GAA_Node_Num + 1; ++i)
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
		cout << "=====���� ���=====" << endl;
		for (int i = 1; i < GAA_Node_Num + 1; ++i)
		{
			cout << i << "�� ���� ��� : ";
			ViewAdjacentNode(i);
		}
		cout << endl;
	}
	void ViewGAA() const
	{
		cout << "=====���� ���=====" << endl;
		for (int i = 1; i < GAA_Node_Num + 1; ++i)
		{
			for (int j = 1; j < GAA_Node_Num + 1; ++j)
			{
				cout << GAA_Array[i][j] << ' ';
			}
			cout << endl;
		}
	}
};

int main(void)
{
	int test_case = 1;
	int NumberOfNode = 1;
	int NumberOfEdge = 1;
	int start_buffer = 1, end_buffer = 1;

	/*
	ifstream in("TestCase_graph1.txt");

	if (!in.is_open())
		cout << "������ ã�� �� �����ϴ�." << endl;
		*/
	//scanf("%d", &test_case);
	//in >> test_case;
	cout << "Test Case ���� : ";
	cin >> test_case;
	Graph_Adjacent_Array *Graph[5];

	for (int t = 1; t <= test_case; ++t)
	{
		//scanf("%d %d", &NumberOfNode, &NumberOfEdge);
		//in >> NumberOfNode >> NumberOfEdge;
		try
		{
		cout << "��� ����, ���� ���� : ";
		cin >> NumberOfNode >> NumberOfEdge;

			if (NumberOfNode <= 1 || NumberOfEdge <= 0)						//Exception Handling
				throw pair<int, int>(NumberOfNode, NumberOfEdge);

		Graph[t] = new Graph_Adjacent_Array(NumberOfNode, NumberOfEdge);				//graph ��ü ����

			for (int e = 1; e <= NumberOfEdge; ++e)
			{
				//scanf("%d %d", &start_buffer, &end_buffer);
				//in >> start_buffer >> end_buffer;
				try
				{
				cout << "���� ���, Ÿ�� ��� : ";
				cin >> start_buffer >> end_buffer;

					if (start_buffer <= 0 || end_buffer <= 0)
						throw pair<int, int>(start_buffer, end_buffer);

				Graph[t]->AddEdge(start_buffer, end_buffer);
				}
				catch (pair<int, int> expn2)
				{
					cout << "(error) ���� �߰� ����" << endl;
					cout << "error message : " << "��߳�� : " << expn2.first << "Ÿ�ٳ�� : " << expn2.second << endl;
				}
			}
		}
		catch (pair<int, int> expn)
		{
			cout << "#" << t << "(error) graph ���� ����" << endl;
			cout << "error message : �Է¹��� ��� �� : " << expn.first << " / �Է¹��� ���� �� : " << expn.second << endl;
		}
	}

	for (int i = 1; i < test_case + 1; ++i)
	{
		cout << "#" << i << endl;
		Graph[i]->ViewGAA();
		Graph[i]->ViewAdjacentNode();
	}

	for (int t = 0; t < test_case; ++t)
	{
		delete Graph[t];
	}

	//in.close();

	return 0;
}
