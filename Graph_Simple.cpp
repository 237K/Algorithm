//
//	OS Windows
//	2019.01.23
//
//	1) 인접행렬방식 그래프 구현
//		- 객체로 구현한 것과 속도비교를 위해 그냥 main 안에서 2차배열로 구현해봄
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
		cout << "파일이 존재하지 않습니다." << endl;
	else
	{
		//cout << "테스트 케이스 개수 : ";
		//cin >> test_case;
		in >> test_case;
		for (int t = 1; t <= test_case; ++t)
		{
			//cout << "노드 개수, 간선 개수 : ";
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
				//cout << "출발 노드, 타겟 노드 : ";
				//cin >> Start >> End;
				in >> Start >> End;
				graph[Start][End] = 1;
				graph[End][Start] = 1;
			}

			cout << "#" << t << endl;
			cout << "=====인접 행렬=====" << endl;
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