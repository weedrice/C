#include <stdio.h>

int main() {
	int n;
	printf("�ڿ��� �Է�: ");
	scanf("%d", &n);
	int evensum = 0;
	int oddsum = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			evensum += i;
		}
		else {
			oddsum += i;
		}
	}
	printf("%d ���� Ȧ�� ��: %d\n", n, oddsum);
	printf("%d ���� ¦�� ��: %d\n", n, evensum);
}