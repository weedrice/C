#include <stdio.h>

int main() {
	int num;
	printf("10진수 정수 입력: ");
	scanf("%d", &num);

	int answer = 0;
	int numsave = num;
	int n = 1;
	while (num > 0) {
		answer += (num % 2) * n;
		num /= 2;
		n *= 10;
	}

	printf("%d를 2진수로 변환하면 %d", numsave, answer);
}