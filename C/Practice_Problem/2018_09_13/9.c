#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int search(int *A, int size, int search_value)
{
	int i;
	int result;
	for (i = 0; i < size; i++)
	{
		if (A[i] == search_value)
		{
			result = i;
		}
	}

	return result;
}

int main(void)
{
	int A[5] = { 100, 200, 300, 400, 500 };
	int size = 5;
	int search_value;
	int num;

	printf("ã����� ������?");
	scanf("%d", &search_value);

	num = search(A, size, search_value);
	
	printf("ã�� ������ %d��° �����̴�.\n", num+1);

	system("pause");
}

