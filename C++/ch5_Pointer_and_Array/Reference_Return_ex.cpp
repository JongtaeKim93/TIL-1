#include <iostream>
using namespace std;

char& find(char s[], int index) {
	return s[index];	// ���� ����
}

int main() {
	char name[] = "Mike";
	cout << name << endl;

	find(name, 0) = 'S';	// name[0]�� ��ġ�� �����ͼ� 'S' �� ����
	cout << name << endl;

	char& ref = find(name, 2);	// name[2]�� ��ġ�� �����ͼ� ref �ּҿ� �ִ´�.
	ref = 't';	// name[2]�� �ּҸ� 't'�� �ٲ��ش�. name = "Site"
	cout << name << endl;
}