#include <stdio.h>

int main() {
	int n;
	while (1) {
		printf("1 이상의 정수 입력: ");
		scanf("%d", &n);
		if (n < 1)
			printf("1 이상의 정수를 입력해야 합니다.\n");
		else
			break;
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	printf("1부터 %d까지의 합은 %d\n", n, sum);
}