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
	//������
	explicit Graph_Adjacent_Array(int _Node_Num, int _Edge_Num) : GAA_Node_Num(_Node_Num), GAA_Edge_Num(_Edge_Num)
	{
		try
		{
			if (_Node_Num <= 0 || _Edge_Num <= 0)					//Exception Handling
				throw pair<int, int>(_Node_Num, _Edge_Num);

			GAA_Array = new int *[_Node_Num];						//�� ���� �Ҵ�
			for (int i = 0; i < _Node_Num; ++i)
			{
				GAA_Array[i] = new int[_Node_Num];					//�� �� ���� �� ���� �Ҵ�
				memset(GAA_Array[i], 0, sizeof(int)*_Node_Num);		//�迭 �ʱ�ȭ
			}
		}
		catch (pair<int, int> expn)
		{
			cout << "(error) graph ���� ����" << endl;
			cout << "error message : �Է¹��� ��� �� : " << expn.first << " / �Է¹��� ���� �� : " << expn.second << endl;
		}
	}
	
	//�Ҹ���
	~Graph_Adjacent_Array()
	{
		for (int i = 0; i < GAA_Node_Num; ++i)
		{
			delete[] GAA_Array[i];
		}
		delete[] GAA_Array;
	}

	//Edge(����) �߰�
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
			cout << "(error) ���� �߰� ����" << endl;
			cout << "error message : ��� ��� Ȥ�� Ÿ�� ��� ���� 0���� �Դϴ�." << endl;
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
		cout << "=====���� ���=====" << endl;
		for (int i = 0; i < GAA_Node_Num; ++i)
		{
			cout << i << "�� ���� ��� : ";
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
