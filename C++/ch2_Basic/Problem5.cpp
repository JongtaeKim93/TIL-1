#include <iostream>
#include <string>
using namespace std;

int main() {
	char str[100];
	int i;
	int count = 0;
	cout << "���ڵ��� �Է��϶�(100�� �̸�).\n";

	cin.getline(str, 100, '\n');
	for (i = 0; i < 100; i++)
	{
		if ( str[i] == 'x' )
		{
			count++;
		}
	}
	cout << "x�� ������ " << count << endl;
}