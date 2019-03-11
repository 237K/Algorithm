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
//				- key를 인덱스값으로 사용하려면 매우 큰 배열이 필요하므로 적합하지 않음
//			3) 해시 함수 추가
//

#include <iostream>
using namespace std;

class Employee
{
public:
	int empNum;
	int age;
public:
	Employee(int _empNum = 0, int _age = 0) : empNum(_empNum), age(_age) {}
	Employee& operator=(const Employee& emp)
	{
		empNum = emp.empNum;
		age = emp.age;
		return *this;
	}
	int GetHashValue(int _empNum)
	{
		return _empNum % 100;
	}
};

class Manager
{
private:
	Employee empArr[100];
	int numOfemp;
public:
	Manager() : numOfemp(0) {}
	int Input(int _empNum, int _age)
	{
		Employee tempEmp;
		tempEmp.empNum = _empNum;
		tempEmp.age = _age;
		int HV = tempEmp.GetHashValue(_empNum);
		empArr[HV] = tempEmp;
		numOfemp++;
		return HV;
	}
	void ShowInfo(int hv)
	{
		cout << "사번 : " << empArr[hv].empNum << ", 나이 : " << empArr[hv].age << endl << endl;
	}
};

int main(void)
{
	Manager manager;
	int HashValue1, HashValue2, HashValue3;

	HashValue1 = manager.Input(20120003, 42);
	HashValue2 = manager.Input(20130012, 33);
	HashValue3 = manager.Input(20170049, 27);

	manager.ShowInfo(HashValue1);
	manager.ShowInfo(HashValue2);
	manager.ShowInfo(HashValue3);

	return 0;
}