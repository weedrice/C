#include <stdio.h>

int main() {
	int n;
	while (1) {
		printf("1 �̻��� ���� �Է�: ");
		scanf("%d", &n);
		if (n < 1)
			printf("1 �̻��� ������ �Է��ؾ� �մϴ�.\n");
		else
			break;
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	printf("1���� %d������ ���� %d\n", n, sum);
}