#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;

	cout << "���ڿ��� �Է��ϼ���(�ѱ� �ȵ�) " << endl;
	getline(cin, s, '\n');
	int len = s.length();

	for (int i = 0; i < len; i++) {
		string first = s.substr(0, 1);
		string sub = s.substr(1, len - 1);
		s = sub + first;
		cout << s << endl;
	}
}

/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	string names[5];

	for (int i = 0; i < 5; i++)
	{
		cout << "�̸� : ";
		getline(cin, names[i], '\n');
	}

	string latter = names[0];
	for (int i = 1; i < 5; i++)
	{
		if (latter < names[i]) {
			latter = names[i];
		}
	}
	cout << "�������� ���� �ڿ� ������ ���ڿ��� " << latter << endl;
}
*/