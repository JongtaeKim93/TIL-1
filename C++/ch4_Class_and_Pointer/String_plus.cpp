#include <iostream>
#include <string>
using namespace std;

int main() {
	string a = "Java", b = "C++";
	cout << "a = " << a << "\nb = " << b << endl;
	a = b;
	cout << "���ڿ� ġȯ a = b" << endl;
	cout << "a = " << a << "\nb = " << b << endl;

	string name = "Kitae";
	string alias = "Kito";

	int res = name.compare(alias);
	cout << "\n���ڿ� ������ �񱳹�";
	if (res == 0) cout << "�� ���ڿ��� ����." << endl;
	else if (res < 0) cout << name << " < " << alias << endl;	// name�� �տ� ��
	else cout << alias << " < " << name << endl;	// name�� �ڿ� ��

	cout << "\n���ڿ� �񱳹�" << endl;
	if (name == alias) cout << "�� ���ڿ��� ����." << endl;
	else cout << name << " �� " << alias << " �� " << "�� ���ڿ��� �ٸ���.\n" << endl;

	cout << "���ڿ� ����" << endl;
	string link("I");
	link.append(" love ");	
	cout << link << endl;

	cout << "\n���ڿ� ����" << endl;
	string test_1("I love C++");
	test_1.erase(0, 2);		// ó������ 2���� ���� ����
	cout << test_1 << endl;
	test_1.clear();		// a = " "
	cout << test_1 << endl;

	cout << "\n���ڿ� ���꽺Ʈ��" << endl;
	string test_2("I love C++");
	string test_3 = test_2.substr(2, 4);	// test2 �� �ε��� 2���� 4���� ���� ����
	string test_4 = test_2.substr(2);		// test2 �� �ε��� 2���� ������ ����
	cout << test_2 << endl;
	cout << test_3 << endl;
	cout << test_4 << endl;

	string e = "I love love C++";
	int index = e.find("love"); // e���� "love" �˻�. �ε��� 2 ����
	index = e.find("love", index+1); // e�� �ε��� 3 ���� "love" �˻�, �ε��� 7 ����
	index = e.find("C#"); // e���� "C#"�� �߰��� �� ����. -1 ����
	index = e.find('v', 7); // e�� �ε��� 7���� ��v�� ���� �˻�, �ε��� 9 ����
	string f("I love C++");
	char ch1 = f.at(7);		// ���ڿ� f�� �ε��� 7�� �ִ� ���� ����
	char ch2 = f[7];		// f.at(7) �� ����
	char ch3 = f.at(f.length() - 1);	// ���ڿ� f�� ������ ����.
}