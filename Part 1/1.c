#include <cstdio>

int main() {
	char c;
	int i;
	double d;
	char str[100];
	printf("[����, ����, �Ǽ�, ���ڿ�]�� �������� �Է�: ");
	scanf("%c, %d, %lf, %s", &c, &i, &d, &str);

	printf("�Էµ� ������ ���: %c, %d, %lf, %s", c, i, d, str);
}