#include <stdio.h>

int main() {
	int a, b, c;
	printf("�� ���� ���ڸ� �Է��ϼ���: ");
	scanf("%d %d %d", &a, &b, &c);

	printf("ū ���� %d", a > (b > c ? b : c) ? a : (b > c ? b : c));
}