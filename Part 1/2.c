#include <stdio.h>

int main() {
	char str[100];
	printf("문자열 입력: ");
	gets(str);

	printf("입력된 문자열: %s", str);
}