#include <stdio.h>

int main() {
	int n;
	int ret;
	
	while (1) {
		printf("1 �̻��� ���� �Է�: ");
		ret = scanf("%d", &n);

		if (ret == EOF)
			break;
		else if (n < 1)
			printf("1 �̻��� �Է��� �ʿ�� �մϴ�. �ٽ� �Է��ϼ���.\n");
		else {
			printf("%d�� �����\n", n);
			for (int i = 1; i <= n; i++) {
				if (n % i == 0)
					printf("%d ", i);
			}
			printf("\n");
		}
	}
	printf("EOF �Է¿� ���� ���α׷��� �����մϴ�.\n");
}