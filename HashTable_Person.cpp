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
		name = _name;
		address = _add;
	}
	Person& operator= (const Person& p)
	{
		ssn = p.ssn;
		name = p.name;
		address = p.address;
		return *this;
	}
	void MakePersonData(int _ssn, string _name, string _add)
	{
		ssn = _ssn;
		name = _name;
		address = _add;
	}
	int GetSSN()
	{
		return ssn;
	}
	friend ostream& operator<< (ostream& os, const Person& p);
};

ostream& operator<< (ostream& os, const Person& p)
{
	os << "이름 : " << p.name << endl;
	os << "주민등록번호 : " << p.ssn << endl;
	os << "주소 : " << p.ssn << endl << endl;
	return os;
}

class Slot
{
public:
	int Key;
	Person person;
	SlotStatus status;
public:
	Slot(int _ssn = 0, string _name = NULL, string _add = NULL, int key = 0) : Key(key), person(_ssn, _name, _add), status(EMPTY) {}
	friend ostream& operator<< (ostream& os, const Slot& s);
};

ostream& operator<< (ostream& os, const Slot& s)
{
	os << s.person << endl;
	return os;
}

class Table
{
private:
	Slot table[TABLE_SIZE];
	HashFunc *HF;
public:
	Table(int _ssn = 0, string _name = NULL, string _add = NULL, int key = 0, HashFunc *f = NULL)
	{
		HF = f;
		for (int i = 0; i < TABLE_SIZE; ++i)
		{
			int hv = f(i);
			table[hv](_ssn, _name, _add, key);
		}
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
		else
		{
			table[HV].status = DELETED;
			return table[HV].person;
		}
	}
	Person Search(int key)
	{
		int HV = HF(key);
		if (table[HV].status != INUSE)
			return NULL;
		else
			return table[HV].person;
	}
};

int hashfunc(int k)
{
	return k % 100;
}

int main(void)
{
	Table T(hashfunc);
	Person p1;
	Person p2;
	Person p3;

	p1.MakePersonData(20120003, "LEE", "Seoul");
	p2.MakePersonData(20130012, "KIM", "Pusan");
	p3.MakePersonData(20092455, "HYEONG", "Seoul");

	T.Insert(p1.GetSSN(), p1);
	T.Insert(p2.GetSSN(), p2);
	T.Insert(p3.GetSSN(), p3);

	Person pc1;
	Person pc2;
	Person pc3;

	pc1 = T.Search(20120003);
	pc2 = T.Search(20130012);
	pc3 = T.Search(20092455);

	cout << pc1 << pc2 << pc3;


	return 0;
}