#include <stdio.h>

int main() {
	int n, m;
	printf("�� ���� 16������ �Է�: ");
	scanf("%x %x", &n, &m);

	printf("���� ��� 8����: %o\n", n + m);
	printf("���� ��� 10����: %d\n", n + m);
	printf("���� ��� 16����: %x\n", n + m);
}