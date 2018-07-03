#include <stdio.h>

int main() {
	int n1, n2;
	printf("두 개의 정수 입력: ");
	scanf("%d %d", &n1, &n2);
	int sum = 0;
	int i = n1 > n2 ? n2 : n1;
	int max = n1 > n2 ? n1 : n2;
	for (; i < max; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			printf("%d는 합에서 제외.\n", i);
		}
		else {
			sum += i;
		}
	}

	printf("%d와 %d를 포함하여 그 사이에 있는 정수들의 합: %d\n", n1, n2, sum);
}