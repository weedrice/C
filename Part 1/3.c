#include <stdio.h>

int main() {
	int n, m;
	printf("두 수를 16진수로 입력: ");
	scanf("%x %x", &n, &m);

	printf("연산 결과 8진수: %o\n", n + m);
	printf("연산 결과 10진수: %d\n", n + m);
	printf("연산 결과 16진수: %x\n", n + m);
}