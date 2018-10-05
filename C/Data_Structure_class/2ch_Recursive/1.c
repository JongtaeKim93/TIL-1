#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int permutation(int n, int r);
int permutation2(int n, int r);
int sum2 = 1;

int main(void)
{
	int n, r;

	printf("n�� �Է�: ");
	scanf("%d", &n);

	printf("r�� �Է�: ");
	scanf("%d", &r);

	permutation(n, r);
	sum2 = permutation2(n,r);

	
	printf("��ȯ������ ���� �� : %d\n", sum2);

}

int permutation(int n, int r)
{
	int i;
	int sum = 1;

	for (i = n; r > 0 ; i--, r--)
	{
		sum *= i;
	}
	
	printf("�ݺ������� ���� �� : %d\n", sum);

}

int permutation2(int n, int r)
{
	
	if (n == 1 || r == 0)
		return 1;
	return (n - r + 1) * permutation2(n, r - 1);

}