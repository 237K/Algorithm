//
//	OS Windows
//	2019.03.11
//
//	[Ž�� �˰���]
//		<1. ���� Ž��>
//		<2. ���� Ž�� (Interpolation Search)>
//		<3. ���� Ž�� Ʈ��>
//		<4. ���� ���� ���� Ž�� Ʈ��>
//		<4-1. AVL Ʈ��>
//		<5. �ؽ� ���̺�>
//			1) ��� �����ʹ� key�� ������. ��� key�� �ߺ����� �ʴ´�.
//			2) �迭 ��� ���̺�
//				- key�� �ε��������� ����Ϸ��� �ſ� ū �迭�� �ʿ��ϹǷ� �������� ����
//			3) �ؽ� �Լ� �߰�
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
		cout << "��� : " << empArr[hv].empNum << ", ���� : " << empArr[hv].age << endl << endl;
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