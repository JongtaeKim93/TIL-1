#include "Tower.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	Tower myTower;
	Tower seoulTower(100);

	cout << "���̴� " << myTower.getHeight() << " ����" << endl;
	cout << "���̴� " << seoulTower.getHeight() << " ����" << endl;

	system("pause");
}