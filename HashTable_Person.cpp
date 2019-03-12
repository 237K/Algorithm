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
#include <string>
using namespace std;

const static int LENGTH = 50;
const static int TABLE_SIZE = 100;
typedef int HashFunc(int k);

enum SlotStatus {EMPTY, DELETED, INUSE};


class Person
{
private:
	int ssn;
	string name;
	string address;
public:
	Person(int _ssn = 0, string _name = NULL, string _add = NULL) : ssn(ssn)
	{
		strcpy(name, _name);
		strcpy(address, _add);
	}
	Person* operator= (const Person& p)
	{
		ssn = p.ssn;
		name = p.name;
		address = p.address;
	}
	int GetSSN(Person *p)
	{
		return p->ssn;
	}
	void ShowPersonInfo(Person *p)
	{
		cout << "�̸� : " << p->name << endl;
		cout << "�ֹε�Ϲ�ȣ : " << p->ssn << endl;
		cout << "�ּ� : " << p->ssn << endl << endl;
	}
};

class Slot
{
public:
	int Key;
	Person person;
	SlotStatus status;
public:
	Slot() : Key(0)
	{
		status = EMPTY;
	}
};

class Table
{
private:
	Slot table[TABLE_SIZE];
	HashFunc *HF;
public:
	Table(HashFunc *f)
	{
		HF = f;

		for (int i = 0; i < TABLE_SIZE; ++i)
			table[i].status = EMPTY;
	}
	void Insert(int key, Person p)
	{
		int HV = HF(key);
		table[HV].Key = key;
		table[HV].person = p;
		table[HV].status = INUSE;
	}
	Person Delete(int key)
	{
		int HV = HF(key);
		if (table[HV].status != INUSE)
			return NULL;
	}
};