#ifndef Circle_H
#define Circle_H

class Circle {
private:
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle(); // �Ҹ���
	double getArea();
	void getRadius();
};

#endif