#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
int *divisor = NULL;
int *backpart = NULL;
unsigned int cnt;
void main(void) {
	int sum_divisor(int);
	/* 우애수 구하는 프로그램 */
	unsigned int i = 1;
	unsigned int getnum;
	divisor = (int *) malloc(sizeof(int) * 1024);
	backpart = (int *) malloc(sizeof(int) * 1024);
	puts("수를 입력하시오.");
	printf(":");
	scanf("%d", &getnum);
	while (i < 2147483648U) {
		if (sum_divisor(getnum) == i && sum_divisor(i) == getnum) {
			printf("우애수는 %d 입니다.\n", i);
			break;
		}
		i++;
	}
	getch(); /* system(pause)을 대체합니다. */
	free(divisor);
}
void calc_divisor(unsigned int n, unsigned int scope, unsigned int num,
		unsigned int start) {
	extern int unsigned cnt;
	cnt = n;
	unsigned int i = start;
	while (i < scope) {
		if (num % i == 0) {
			if (i <= num / i) {
				divisor[n] = i;
				backpart[n] = num / i;
				if (num / i > i + 1)
					calc_divisor(n + 1, num / i, num, i + 1);
				break;
			}
		}
		i++;
	}
	/* merge */
	if (i + 1 > num / i) {
	divisor[0] = 1;
		n--;
		unsigned int p = n;
		while (p != 0) {
			if (divisor[n] != backpart[p]) {
				n++;
				divisor[n] = backpart[p];
			}
			cnt++;
			p--;
		}
		free(backpart);
	divisor[cnt] = num;
	}
}
int sum_divisor(int num) {
	unsigned int i = 0;
	unsigned int sum_divisor = 0;
	extern unsigned int cnt;
	calc_divisor(1, num, num, 2);
	while (i < cnt) {
		sum_divisor += divisor[i];
		i++;
	}
	return sum_divisor;
}
