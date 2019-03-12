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

const static int TABLE_SIZE = 100;
typedef int HashFunc(int k);

enum SlotStatus {EMPTY, DELETED, INUSE};

typedef struct _person
{
	int ssn;
	string name;
	string add;
} Person;

static int GetSSN(Person *p)
{
	return p->ssn;
}

static void ShowPersonInfo(Person *p)
{
	cout << "이름 : " << p->name << endl;
	cout << "주민등록번호 : " << p->ssn << endl;
	cout << "주소 : " << p->add << endl << endl;
}

static Person* MakePersonData(int ssn, string name, string add)
{
	Person *p = new Person();
	p->ssn = ssn;
	p->name = name;
	p->add = add;
	return p;
}


typedef int Key;
typedef Person* Value;

typedef struct _slot
{
	Key key;
	Value value;
	enum SlotStatus status;
} Slot;


typedef struct _table
{
	Slot table[TABLE_SIZE];
	HashFunc *HF;
} Table;

static void Init(Table *t, HashFunc *f)
{
	for (int i = 0; i < TABLE_SIZE; ++i)
		(t->table[i]).status = EMPTY;

	t->HF = f;
}

static void Insert(Table *t, Key k, Value v)
{
	int hv = t->HF(k);
	(t->table[hv]).value = v;
	(t->table[hv]).key = k;
	(t->table[hv]).status = INUSE;
}

static Value Delete(Table *t, Key k)
{
	int hv = t->HF(k);

	if ((t->table[hv]).status != INUSE)
		return NULL;
	else
	{
		(t->table[hv]).status = DELETED;
		return (t->table[hv]).value;
	}
}

static Value Search(Table *t, Key k)
{
	int hv = t->HF(k);
	if ((t->table[hv]).status != INUSE)
		return NULL;
	else
		return (t->table[hv]).value;
}

int MyHashFunc(int k)
{
	return k % 100;
}

int main(void)
{
	Table T;
	Init(&T, MyHashFunc);

	Person *p1;
	Person *p2;
	Person *p3;

	p1 = MakePersonData(20120003, "LEE", "Seoul");
	Insert(&T, GetSSN(p1), p1);
	p1 = MakePersonData(20092455, "HYEONG", "Seoul");
	Insert(&T, GetSSN(p1), p1);
	p1 = MakePersonData(20140712, "KIM", "Pusan");
	Insert(&T, GetSSN(p1), p1);

	p2 = Search(&T, 20092455);
	ShowPersonInfo(p2);
	p2 = Search(&T, 20120003);
	ShowPersonInfo(p2);
	p2 = Search(&T, 20140712);
	ShowPersonInfo(p2);

	p3 = Delete(&T, 20140712);
	p3 = Delete(&T, 20120003);
	p3 = Delete(&T, 20092455);

	return 0;
}