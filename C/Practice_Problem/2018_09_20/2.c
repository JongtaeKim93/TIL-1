#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

double *GRADE = NULL;
double *SCORE = NULL;

void convert(double *grades, double *scores, int size) {
	int i;
	for (i = 0; i < size; i++) {
			scores[i] = grades[i] * 100 / 4.3;
		printf("%d�� �л��� ������ %lf �Դϴ�\n", i, scores[i]);
	}

}

int main(void)
{
	int i;

	GRADE = (double*)malloc(sizeof(double)*SIZE);
	SCORE = (double*)malloc(sizeof(double)*SIZE);
	memset(SCORE, 0, sizeof(SIZE));

	for (i = 0; i < SIZE; i++) {
		printf("%d�л��� ������? ", i);
		scanf("%lf", &GRADE[i]);
	}

	convert(GRADE, SCORE, SIZE);

	free(GRADE);
	free(SCORE);

	system("pause");
}
