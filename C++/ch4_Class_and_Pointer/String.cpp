#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;		// �� ���ڿ��� ���� ��Ʈ�� ��ü
	string address("������ ������ ������� 125");	
	string copyAddress(address);	
	// address�� ���ڿ��� ������ ��Ʈ�� ��ü ����

	char text[] = { 'L','o','v','e',' ','C','+','+','\0' };
	string title(text); // "Love C++" ���ڿ��� ���� ��Ʈ�� ��ü ����

	cout << str << endl;	// �� ��Ʈ��
	cout << address << endl;
	cout << copyAddress << endl;
	cout << title << endl;
}