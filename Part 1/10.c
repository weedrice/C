#include <stdio.h>

int main() {
	int n1, n2;
	printf("�� ���� ���� �Է�: ");
	scanf("%d %d", &n1, &n2);
	int sum = 0;
	int i = n1 > n2 ? n2 : n1;
	int max = n1 > n2 ? n1 : n2;
	for (; i < max; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			printf("%d�� �տ��� ����.\n", i);
		}
		else {
			sum += i;
		}
	}

	printf("%d�� %d�� �����Ͽ� �� ���̿� �ִ� �������� ��: %d\n", n1, n2, sum);
}