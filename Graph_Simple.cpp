//
//	OS Windows
//	2019.01.23
//
//	1) ������Ĺ�� �׷��� ����
//		- ��ü�� ������ �Ͱ� �ӵ��񱳸� ���� �׳� main �ȿ��� 2���迭�� �����غ�
//

#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
	int test_case;
	int Node[10] = { 0 };
	int Edge[10] = { 0 };
	int Start, End;
	int graph[100][100] = { 0 };

	ifstream in("TestCase_graph1.txt");

	if (!in.is_open())
		cout << "������ �������� �ʽ��ϴ�." << endl;
	else
	{
		//cout << "�׽�Ʈ ���̽� ���� : ";
		//cin >> test_case;
		in >> test_case;
		for (int i = 0; i < test_case; ++i)
		{
			//cout << "��� ����, ���� ���� : ";
			//cin >> Node[i] >> Edge[i];
			in >> Node[i] >> Edge[i];
			for (int e = 0; e < Edge[i]; ++e)
			{
				//cout << "��� ���, Ÿ�� ��� : ";
				//cin >> Start >> End;
				in >> Start >> End;
				graph[Start][End] = 1;
				graph[End][Start] = 1;
			}
		}

		for (int i = 0; i < test_case; ++i)
		{
			cout << "#" << i + 1 << endl;
			cout << "=====���� ���=====" << endl;
			for (int j = 0; j < Node[i]; ++j)
			{
				for (int k = 0; k < Node[i]; ++k)
				{
					cout << graph[j+1][k+1] << ' ';
				}
				cout << endl;
			}
			cout << endl << endl;
		}
	}

	in.close();

	return 0;
}