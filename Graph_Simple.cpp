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
	int Node;
	int Edge;
	int Start, End;
	int graph[100][100];

	ifstream in("TestCase_graph1.txt");

	if (!in.is_open())
		cout << "������ �������� �ʽ��ϴ�." << endl;
	else
	{
		//cout << "�׽�Ʈ ���̽� ���� : ";
		//cin >> test_case;
		in >> test_case;
		for (int t = 1; t <= test_case; ++t)
		{
			//cout << "��� ����, ���� ���� : ";
			//cin >> Node[i] >> Edge[i];
			in >> Node >> Edge;

			for (int n = 1; n <= Node; ++n)
			{
				for (int m = 1; m <= Node; ++m)
				{
					graph[n][m] = 0;
				}
			}

			for (int e = 1; e <= Edge; ++e)
			{
				//cout << "��� ���, Ÿ�� ��� : ";
				//cin >> Start >> End;
				in >> Start >> End;
				graph[Start][End] = 1;
				graph[End][Start] = 1;
			}

			cout << "#" << t << endl;
			cout << "=====���� ���=====" << endl;
			for (int n = 1; n <= Node; ++n)
			{
				for (int m = 1; m <= Node; ++m)
				{
					cout << graph[n][m] << ' ';
				}
				cout << endl;
			}
			cout << endl << endl;
		}
	}

	in.close();

	return 0;
}