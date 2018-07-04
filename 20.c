#include <stdio.h>

void DivInt(int a, int b, int* c, int* d) {
	c = a / b;
	d = a % b;
}

int main() {
	int a, b;
	while (1) {
		printf("나눗셈 위한 두 정수 입력: ");
		scanf("%d %d", &a, &b);
		if (b == 0) {
			printf("0으로 나누는 오류 발생! 숫자 재 입력\n");
		}
		else {
			break;
		}
	}

	int c, d;
	DivInt(a, b, &c, &d);
	printf("몫: %d, 나머지: %d\n", a / b, a%b);
}