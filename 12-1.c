#include <stdio.h>

int main() {
	int n;
	while (1) {
		printf("Ȧ�� ��(1), ¦�� ��(2): ");
		scanf("%d", &n);
		if (n != 1 || n != 2)
			printf("�߸��� �Է��Դϴ�. 1 �Ǵ� 2�� �Է��ϼ���.\n");
		else
			break;
	}

	for (int i = 1; i <= 9; i++) {
		if (n == 1 && i % 2 == 1) {
			for (int j = 1; j <= 9; j++) {
				printf("%d X %d = %d\n", i, j, i*j);
			}
		}
		if (n == 2 && i % 2 == 0) {
			for (int j = 1; j < 10; j++) {
				printf("%d X %d = %d\n", i, j, i*j);
			}
		}
	}
}