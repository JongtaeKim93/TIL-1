#include <iostream>
#include <string>
using namespace std;

int main() {
	char password[100];
	char check[100];

	cout << "�� ��ȣ�� �Է��ϼ���>> ";
	cin.getline(password, 100, '\n');

	cout << "�� ��ȣ�� �ٽ� �� �� �Է��ϼ���>> ";
	cin.getline(check, 100, '\n');

	if (strcmp(password, check) == 0)
	{
		cout << "�����ϴ�." << endl;
	}
	else
	{
		cout << "�ٸ��ϴ�." << endl;
	}
}