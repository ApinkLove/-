#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
unsigned int n = 0; // 이 프로그램에서 두 함수의 연결고리
int *divisor = NULL; // 포인터를 초기화
int main(void) {
	unsigned int p = 0;
	unsigned int getnum;
	puts("약수를 구하고자 하는 숫자를 입력해주세요.");
	printf(":");
	scanf("%d", &getnum); // 사용자는 자신의 의도하는 수를 입력한다.
	divisor = (int *) malloc(sizeof(int) * 2048); // int범위안 최대 약수의 개수는 2048개 이다.
	get_divisor(n, getnum, getnum, 1);
	while (p < n) {                  // 약수를 출력하게 했다. 이 부분부터는 사용자가 원하는대로 조작하면 된다.
		printf("%d\n", divisor[p]);
		p++;
	}
	free(divisor); // 메모리 누수 방지
	printf("\n");
	system("pause"); // 윈도우 종특이다 ;;
	return 0;
}
void get_divisor(unsigned int cnt, unsigned int scope, unsigned int num,
		unsigned int used) {
	unsigned int i = used; // 전 과정에서 끊겻던 수 다음부터 이어가는 원리
	while (i <= scope) {
		if (num % i == 0) {
			if (i == scope) {
				divisor[cnt] = i; // 약수를 저장해둔다.
			}
			divisor[cnt] = i;
			cnt++;
			get_divisor(cnt, num / i, num, i + 1); // cnt는 소중하니까요 >.< , i+1 하는 이유는 다음에 그 다음수부터 이어 진행하라고
		}
		i++; // 반복이 끊길 수 있게 하기 위해
	}
	divisor[cnt] = num / i; // 곱해졌던 수도 결국은 약수
	n = cnt; // 내가 임의로 출력하게 한 코드에서는 이 구문이 필요하다. 이게 없으면 반복이 불가능하다.
}
