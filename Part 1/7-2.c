#include <stdio.h>

int main() {
	int a, b, c;
	printf("세 개의 숫자를 입력하세요: ");
	scanf("%d %d %d", &a, &b, &c);

	printf("큰 수는 %d", a > (b > c ? b : c) ? a : (b > c ? b : c));
}