#include <iostream>
using namespace std;

int main() {
	cout << "�ּҸ� �Է��ϼ��� : ";

	char address[100];

	cin.getline(address, 100, '\n');
	// ��ĭ�� �־ <Enter> Ű�� �Էµ� �� ���� �ϳ��� ���ڿ��� �ν�

	cout << "�ּҴ� " << address << " �Դϴ�.\n";
}