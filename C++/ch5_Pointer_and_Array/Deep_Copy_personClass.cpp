#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person {
	char *name;
	int id;
public:
	Person(int id, char* name);		// ������
	Person(Person& person);			// ���� ������
	~Person();						// �Ҹ���
	void changeName(char *name);	// �̸��� �ٲ��� �Լ�
	void show() {		// �̸��� ��½����ִ� �Լ�
		cout << id << '.' << name << endl;
	}
};

Person::Person(int id, char* name) {	// ������
	this->id = id;			// id ����
	int len = strlen(name);	// name�� ���� ���� ����
	this->name = new char[len + 1];		// name ���ڿ� ���� �Ҵ�
	strcpy(this->name, name);			// name�� ���ڿ� ����
}

Person::Person(Person &person) {		// ���� ������
	this->id = person.id;				// id �� ����
	int len = strlen(person.name);		// person.name�� ���� ���� ����
	this->name = new char[len + 1];		// person.name�� ���� ���縦 ����
	strcpy(this->name, person.name);	// person.name�� ���� ����
	cout << "���� ������ ����. ���� ��ü�� �̸� " << this->name << endl;
}

Person::~Person() {
	if (name)			// ���� name�� ���� �Ҵ�� �迭�� ������
		delete[] name;	// ���� �Ҵ� �޸� �Ҹ�
}

void Person::changeName(char *name) {		// �̸� ����
	if (strlen(name) > strlen(this->name))	
		// ���� name�� �Ҵ�� �޸� ���� �� �̸����� �ٲ� �� ����.
		return;
	strcpy(this->name, name);
}

int main() {
	Person father(1, "Kitae");		// father ��ü ����
	Person daughter(father);		// daughter ��ü ���� ����. ���� ������ ȣ��

	cout << "daughter ��ü ���� ����" << endl;
	father.show();		// father ��ü ���
	daughter.show();	// daughther ��ü ���

	daughter.changeName("Grace");	// �̸� ����
	cout << "daughter �̸��� Grace�� ������ ��" << endl;
	father.show();	
	daughter.show();

	return 0;
}