//
//	OS Windows
//	2019.03.11
//
//	[탐색 알고리즘]
//		<1. 이진 탐색>
//		<2. 보간 탐색 (Interpolation Search)>
//		<3. 이진 탐색 트리>
//		<4. 균형 잡힌 이진 탐색 트리>
//		<4-1. AVL 트리>
//		<5. 해시 테이블>
//			1) 모든 데이터는 key를 가진다. 모든 key는 중복되지 않는다.
//			2) 배열 기반 테이블
//

#include <iostream>
using namespace std;

class Employee
{
public:
	int empNum;
	int age;
};

class Manager
{
private:
	Employee empArr[100];
	int numOfemp;
public:
	Manager() : numOfemp(0) {}
	void Input(int _empNum, int _age)
	{
		empArr[_empNum].empNum = _empNum;
		empArr[_empNum].age = _age;
		numOfemp++;
	}
	void ShowInfo(int _empNum)
	{
		cout << "사번 : " << empArr[_empNum].empNum << ", 나이 : " << empArr[_empNum].age << endl << endl;
	}
};

int main(void)
{
	Manager manager;
	int eNum;
	int eAge;
	
	cout << "사번과 나이 입력 : ";
	cin >> eNum >> eAge;
	manager.Input(eNum, eAge);
	cout << endl;

	cout << "확인하고자 하는 직원의 사번 입력 : ";
	cin >> eNum;
	cout << endl;
	manager.ShowInfo(eNum);
	cout << endl;

	return 0;
}