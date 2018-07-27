#include <stdio.h>
#include <string.h>

int main() {
	char str[256];
	int length;

	printf("문자열 입력: ");
	gets(str);
	length = strlen(str);

	for (int i = 0; i < length; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - 32;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + 32;
		}
	}

	puts(str);
}