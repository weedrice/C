#include <stdio.h>

void DivInt(int a, int b, int* c, int* d) {
	c = a / b;
	d = a % b;
}

int main() {
	int a, b;
	while (1) {
		printf("������ ���� �� ���� �Է�: ");
		scanf("%d %d", &a, &b);
		if (b == 0) {
			printf("0���� ������ ���� �߻�! ���� �� �Է�\n");
		}
		else {
			break;
		}
	}

	int c, d;
	DivInt(a, b, &c, &d);
	printf("��: %d, ������: %d\n", a / b, a%b);
}