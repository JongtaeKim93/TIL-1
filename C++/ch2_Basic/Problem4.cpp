#include <iostream>
using namespace std;

int main() {
	double a[5];
	int i;
	double max = 0;
	cout << "5 ���� �Ǽ��� �Է��϶�>> ";
	cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
	
	for (i = 0; i < 5; i++)
	{
		if (max < a[i])
			max = a[i];
	}

	cout << "���� ū �� = " << max << endl;
}