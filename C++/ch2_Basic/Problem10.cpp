#include <iostream>
using namespace std;

int main() {
	int i, j;
	char str[10];

	cout << "���ڿ� �Է�>> ";
	cin.getline(str, 100, '\n');

	for (i = 0; i <= 4; i++) {
		for (j = 0; j <= i; j++) {
			cout << str[j];

		}cout << '\n';
		
	}

}