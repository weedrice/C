#include <stdio.h>
#include <string.h>

int main() {
	char arr1[21];
	char arr2[21];
	char arr3[21];
	char arr4[21];
	char *arr[4] = { arr1, arr2, arr3, arr4 };
	char total[81] = "";

	for (int i = 0; i < 4; i++) {
		printf("문자열 입력%d: ", i+1);
		gets(arr[i]);
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3 - i; j++) {
			if (strcmp(arr[j], arr[j + 1]) > 0) {
				char temp[21];
				strcpy(temp, arr[j + 1]);
				strcpy(arr[j + 1], arr[j]);
				strcpy(arr[j], temp);
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		strcat(total, arr[i]);
		strcat(total, " ");
	}

	printf("정렬된 문자열: %s\n", total);
}