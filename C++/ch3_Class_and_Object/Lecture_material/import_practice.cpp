#include <iostream>
using namespace std;

#include "Circle.h"
#include "Circle.h" // #ifndef Circle_H , #define Circle_H, #endif
// �� �̿��ؿ� ������ ������ �ʴ´�.

void Circle::getRadius() {
	cout << "�������� " << radius << "�Դϴ�." << endl;
}

Circle::Circle() {
	radius = 1;
	cout << "������ " << radius << " �� ����" << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "������ " << radius << " �� ����" << endl;
}

Circle::~Circle() {
	cout << "������ " << radius << " �� �Ҹ�" << endl;
}

inline double Circle::getArea() {
	return 3.14*radius*radius;
}

int main() {
	Circle donut;
	Circle pizza(30);
	pizza.getRadius();
}