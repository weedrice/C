#include <stdio.h>
#include <string.h>

int count(char* str, char c) {
	int count = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == c)
			count++;
	}
	return count;
}

int main() {
	char str[101];
	char c;

	printf("��� ���ڿ� �Է�: ");
	gets(str);

	printf("���� �� ���� �Է�: ");
	c = getchar();

	printf("%c�� ����: %d\n", c, count(str, c));
}