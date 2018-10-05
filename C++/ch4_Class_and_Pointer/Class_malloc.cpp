#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	double getArea() { return 3.14 * radius * radius; }
	void setRadius(int r) { radius = r; }
};

Circle::Circle() {
	radius = 1;
	cout << "������ ���� radius = " << radius << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "������ ���� radius = " << radius << endl;
}

Circle::~Circle() {
	radius = 1;
	cout << "�Ҹ��� ���� radius = " << radius << endl;
}

int main() {
	Circle *p, *q;
	p = new Circle;		// ��ü�� ���� ����
	q = new Circle(30);	// ��ü�� ���� ����

	cout << p->getArea() << endl << q->getArea() << endl;
	delete p;
	delete q;
}