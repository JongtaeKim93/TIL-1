// �ǽ� 1 ) ���� �Ű� ������ ���� �Լ� �����
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() {
		radius = 1;
	}
	Circle(int radius) {
		this->radius = radius;
	}
	void setRadius(int radius) {
		this->radius = radius;
	}
	double getArea() {
		return 3.14 * radius * radius;
	}
};

void readRadius(Circle &c) {	// �Ű� ������ �ּҸ� �޴´�.
	int radius;
	cout << "���� ������ �������� �Է��ϼ��� >> ";
	cin >> radius;
	c.setRadius(radius);	// ��ȯ�� ���� �ʾƵ� �Ű������� ���� ��ȯ�ȴ�.
}

int main() {
	Circle donut;
	readRadius(donut);
	cout << "donut�� ���� = " << donut.getArea() << endl;
}