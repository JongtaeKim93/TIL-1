#include <iostream>
/* 1��
P = &a �� a�� �ּҸ� P�� ������ �־��ִ� ���̰�
P = *a �� �������� a�� ���� �����Ͽ� P�� ������ �־��ִ� ���̴�.

*/

//2��

typedef struct student {
	int number;
	char name[20];
	int grade;
};

using namespace std;
int main()
{
	student s1[10];
	int i;


	for (i = 0; i < 10; i++) {
		cout << i << "�� �л�" << endl;
		cout << "�й� : " ;
		cin >> s1[i].number;
		cout << "�̸� : " ;
		cin >> s1[i].name;
		cout << "���� : " ;
		cin >> s1[i].grade;
	}

	int sum = 0;
	int average = 0;

	for (i = 0; i < 10; i++) {
		sum += s1[i].grade;
	}

	average = sum / 10;

	cout << "\n�л����� ��ü ���� : " << sum << endl;
	cout << "��� ���� : " << average << endl;
}