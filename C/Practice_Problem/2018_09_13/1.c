#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void win(int ran, int user);

int main(void)
{
	srand((unsigned)time(NULL));

	int random = rand() % 3 + 1;
	int ran;
	int user;
	
	printf("�����Ͻÿ� (1. ����, 2.����, 3. ��): ");
	scanf("%d", &user);

	if (random == user)
		printf("�����ϴ�.\n");
	else if (random != user)
	{
		if (random == 1)
		{
			if (user == 2)
				printf("�̰���ϴ�.\n");
			else
				printf("�����ϴ�.\n");
		}
		if (random == 2)
		{
			if (user == 3)
				printf("�̰���ϴ�.\n");
			else
				printf("�����ϴ�.\n");
		}
		if (random == 3)
		{
			if (user == 1)
				printf("�̰���ϴ�.\n");
			else
				printf("�����ϴ�.\n");
		}
	}
	
	system("pause");
	
}

