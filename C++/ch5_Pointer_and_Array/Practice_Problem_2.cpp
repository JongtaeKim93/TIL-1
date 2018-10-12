#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Book {
	char *title;	// ���� ���ڿ�
	int price;		// ����
public:
	Book(char *title, int price);	// �ʱ�ȭ ������
	~Book();
	Book(Book &b);	// ���� ���� ������
	void set(char *title, int price);	// �����̳� ������ �ٲ��ֱ� ���� �Լ�
	void show() {	// ��½�Ű�� �Լ�
		cout << title << '.' << price << " ��" << endl;
	}
};

Book::Book(char *title, int price) {
	int len = strlen(title);			// ���� ����
	this->title = new char[len + 1];	// ���� ���̸�ŭ �迭 ����
	strcpy(this->title, title);			// ���� ����
	this->price = price;				// ���� ����
}
Book::~Book() {
	if (title)			// title�� �����Ҷ�
		delete[] title;
}

void Book::set(char *title, int price) {	// �����̳� ���� �����ϱ� ���� �Լ�
	if (this->title)			// ������ �����ϸ� 
		delete[] this->title;	// �޸� ����
	int len = strlen(title);	// ���� ���� ����
	this->title = new char[len + 1];	// ���� �迭 ����
	strcpy(this->title, title);	// ���� ����
	this->price = price;		// ���� ����
}

Book::Book(Book& b) {
	int len = strlen(b.title);	// b ��ü�� ���� ���� ����
	title = new char[len + 1];	// ���ο� ��ü�� ���� �迭 ����
	strcpy(title, b.title);		// b ��ü�� ���� ����
	price = b.price;			// b ��ü�� ���� ����
}

int main() {
	Book cpp("��ǰC++", 10000);
	Book java = cpp;			// cpp�� ���� �����Ͽ� java�� ����
	java.set("��ǰ�ڹ�", 12000);	// java ��ü ����, �� �����Ͽ� ����
	cpp.show();
	java.show();
}