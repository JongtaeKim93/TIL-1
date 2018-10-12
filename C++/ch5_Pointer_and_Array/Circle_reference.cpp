#include <iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle() {
		radius = 1;
		cout << "������ ���� radius = " << radius << endl;
	}
	Circle(int r) {
		this->radius = r;
		cout << "������ ���� radius = " << radius << endl;
	}
	~Circle() {
		cout << "�Ҹ��� ���� radius = " << radius << endl;
	}
	double getArea() {
		return 3.14 * radius * radius;
	}
	int getRadius() {
		return radius;
	}
	void setRadius(int radius) {
		this->radius = radius;
	}
};

void increaseCircle(Circle &c) {
	// C �� waffle�� �ּҸ� ������ ���Ƿ� waffle�� ���� ������ �ȴ�.
	int r = c.getRadius();
	c.setRadius(r + 1);
}

int main() {
	Circle waffle(30);
	increaseCircle(waffle);
	cout << waffle.getRadius() << endl;
}