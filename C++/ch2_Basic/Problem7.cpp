#include <iostream>
#include <string>
using namespace std;

int main() {
	char check[100];
	
	while (true) {
		cout << "�����ϰ������ yes�� �Է��ϼ���>> ";
		cin.getline(check, 100, '\n');

		if (strcmp(check, "yes") == 0)
		{
			cout << "�����մϴ�..." << endl;
			break;
		}
		
	}
}