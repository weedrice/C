#include <stdio.h>
#include <string.h>

int main() {
	char arr[6][6];
	int length[5];
	for (int i = 0; i < 5; i++) {
		printf("문자열 입력 %d: ", i + 1);
		gets(arr[i]);
		length[i] = strlen(arr[i]);
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4 - i; j++) {
			if (length[j] > length[j + 1]) {
				char temp[5];
				strcpy(temp, arr[j]);
				strcpy(arr[j], arr[j + 1]);
				strcpy(arr[j + 1], temp);

				int templength = length[j];
				length[j] = length[j + 1];
				length[j + 1] = templength;
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		puts(arr[i]);
	}
}