#include <iostream>
using namespace std;

void swap(int *a, int *b) {
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	int m = 2, n = 9;
	cout << "ȣ�� �� : " << " m = " << m << " n = " << n << endl;
	swap(&m, &n);
	cout << "ȣ�� �� : " << " m = " << m << " n = " << n << endl;
	// swap �Լ��� ���� �ּҸ� ������ �����Ƿ� 
	// ���� ����ȴ�.
}