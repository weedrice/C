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

	printf("대상 문자열 입력: ");
	gets(str);

	printf("세어 볼 문자 입력: ");
	c = getchar();

	printf("%c의 개수: %d\n", c, count(str, c));
}