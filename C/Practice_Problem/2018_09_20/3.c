#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct VECTOR{
	int x;
	int y;
}VECTOR;

VECTOR vector_add(VECTOR v1, VECTOR v2) {
	VECTOR v3;
	v3.x = v1.x + v2.x;
	v3.y = v1.y + v2.y;
	printf("v3 = %d, %d\n", v3.x,v3.y);
}

int main(void)
{
	VECTOR a, b;

	printf("v1�� x ��ǥ : ");
	scanf("%d", &a.x);

	printf("v1�� y ��ǥ : ");
	scanf("%d", &a.y);

	printf("v2�� x ��ǥ : ");
	scanf("%d", &b.x);

	printf("v2�� y ��ǥ : ");
	scanf("%d", &b.y);

	vector_add(a, b);

	system("pause");

}