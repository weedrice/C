#include <stdio.h>
#include <string.h>

int main() {
	char str1[100];
	char str2[100];

	FILE *fp = fopen("40-1.txt", "w");
	if (fp == NULL) {
		printf("FILE IS NOT OPENED\n");
		return -1;
	}


	printf("---------문자열 입력 및 저장---------\n");
	printf("첫 번째 문자열: ");
	fgets(str1, 100, stdin);
	fwrite(str1, sizeof(char), strlen(str1), fp);

	printf("두 번째 문자열: ");
	fgets(str2, 100, stdin);
	fwrite(str2, sizeof(char), strlen(str2), fp);
	printf("\n");
	fclose(fp);

	FILE *fp2 = fopen("40-1.txt", "r");
	if (fp == NULL) {
		printf("FILE IS NOT OPENED\n");
		return -1;
	}

	fprintf(stdout, "------- 저장된 문자열 출력 ---------\n");
	int i = 0;
	while (1) {
		fread(str1 + i, sizeof(char), 1, fp);
		if (str1[i] == '\n') {
			str1[i + 1] = 0;
			break;
		}
		i++;
	}
	fprintf(stdout, "첫 번째 문자열: %s", str1);

	i = 0;
	while (1) {
		fread(str2 + i, sizeof(char), 1, fp);
		if (str2[i] == '\n') {
			str2[i + 1] = 0;
			break;
		}
		i++;
	}
	fprintf(stdout, "두 번째 문자열: %s", str2);

	fclose(fp2);
}