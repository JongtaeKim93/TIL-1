#include <iostream>
using namespace std;

#include "Calculatoer.h"
#include "Adder.h"

void Calculator::run() {
	cout << "�� ���� ���� �Է��ϼ���>> ";
	int a, b;
	cin >> a >> b;
	Adder adder(a, b);
	cout << adder.process();
}