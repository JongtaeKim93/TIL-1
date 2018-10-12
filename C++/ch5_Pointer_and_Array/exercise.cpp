#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle();
	~Circle();
	void setRadius(int radius);
	double getArea();
};

Circle::Circle()
{
	this->radius = 1;
	cout << "���� : " << this->radius << endl;
}
Circle::~Circle() {
	cout << "�Ҹ� : " << this->radius << endl;
}
void Circle::setRadius(int radius) {
	this->radius = radius;
	// this->radius �� ��ü�� radius
	// int radius �� �Ű������� radius
}
double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	cout << "���� ����?";
	int n, radius;

	cin >> n;
	Circle *pArray = new Circle[n];	
	// n�� ��ŭ�� Circle ��ü�� �迭�� ��������� Array �����Ϳ� ���� �ȴ�

	for (int i = 0; i < n; i++) {
		cout << i << "��° ���� ������??";
		cin >> radius;
		pArray[i].setRadius(radius);
	}

	int count = 0;
	Circle* p = pArray;
	for (int i = 0; i < n; i++) {
		cout << p->getArea() << "��° ���� ������"<< endl;
		if (p->getArea() > 100) {
			count++;
		}
		p++;
	}
	cout << count << endl;

	delete [] pArray;
}