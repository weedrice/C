#include <stdio.h>

int main() {
	int n;
	printf("2 �̻� �Է�: ");
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

	printf("%d�� ���� �� ó�� %d�� �ѱ� �����Ѵ�.\n", sumCount, n);
	printf("%d�� �ѱ� ������ ��: %d\n", n, beforeCount);
	printf("%d�� ���� ������ ��: %d\n", n, sum);
}