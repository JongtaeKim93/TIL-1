#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
	char name[10];
	int num;
	char phone[15];
}ST;

int main(void)
{
	ST student;
	char name[10];

	printf("�л��� �̸���?");
	scanf("%s", name);

	strcpy(student.name, name);

	printf("�й���? ");
	scanf("%d", &student.num);

	printf("����ó?");
	scanf("%s", &student.phone);

	printf("�̸� : %s\n", student.name);
	printf("�й� : %d\n", student.num);
	printf("����ó : %s\n", student.phone);

	system("pause");
}

