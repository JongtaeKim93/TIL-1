#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int prin(int n)
{
	int sum = 0;

	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
int main(void)
{
	int n, a;
	int sum=0;

	printf("n�� �Է�: ");
	scanf("%d", &n);

	a = prin(n);
	
	printf("N�� �� �ڸ��� �� = %d\n", a);

	system("pause");

}

