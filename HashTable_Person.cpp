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
		cout << "이름 : " << p->name << endl;
		cout << "주민등록번호 : " << p->ssn << endl;
		cout << "주소 : " << p->ssn << endl << endl;
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