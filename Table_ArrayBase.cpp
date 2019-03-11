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
		cout << "��� : " << empArr[_empNum].empNum << ", ���� : " << empArr[_empNum].age << endl << endl;
	}
};

int main(void)
{
	Manager manager;
	int eNum;
	int eAge;
	
	cout << "����� ���� �Է� : ";
	cin >> eNum >> eAge;
	manager.Input(eNum, eAge);
	cout << endl;

	cout << "Ȯ���ϰ��� �ϴ� ������ ��� �Է� : ";
	cin >> eNum;
	cout << endl;
	manager.ShowInfo(eNum);
	cout << endl;

	return 0;
}