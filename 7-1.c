#include <stdio.h>

int main() {
	int a, b;
	printf("두 개의 숫자를 입력하세요: ");
	scanf("%d %d", &a, &b);

	printf("큰 수는 %d\n", a > b ? a : b);
}