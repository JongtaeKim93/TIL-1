#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() {
		radius = 1;
	}
	Circle(int r) {
		radius = r;
	}
	void setRadius(int r) {
		radius = r;
	}
	double Circle::getArea();
};

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle circleArray[3];

	circleArray[0].setRadius(10);
	circleArray[1].setRadius(20);
	circleArray[2].setRadius(30);	// �迭�� ������ �ʱ�ȭ

	for (int i = 0; i < 3; i++)
		cout << "Circle " << i << "�� ������ " << circleArray[i].getArea() << endl;
		// �迭�� ������� ������ ���

	Circle *p;
	p = circleArray;
	for (int i = 0; i < 3; i++) {
		cout << "Circle " << i << "�� ������ " << p->getArea() << endl;
		// �迭�� �����ͷ� ��ȯ���� ������� ������ ���
		p++;
	}
}