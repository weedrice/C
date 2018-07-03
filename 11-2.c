#include <stdio.h>

int main() {
	int n;
	printf("2 이상 입력: ");
	scanf("%d", &n);
	int sum = 0;
	int beforeCount;
	int sumCount = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
		if (sum > n && sumCount == 0) {
			sumCount = i;
			beforeCount = sum - i;
			break;
		}
	}

	printf("%d를 더할 때 처음 %d를 넘기 시작한다.\n", sumCount, n);
	printf("%d를 넘기 이전의 합: %d\n", n, beforeCount);
	printf("%d를 넘은 이후의 합: %d\n", n, sum);
}