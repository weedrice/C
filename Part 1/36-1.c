#include <stdio.h>

int main() {
	char text[] = "�����ٶ󸶹ٻ��������Ÿ��";
	
	FILE *fp = fopen("36-1.txt", "w");
	if (fp == NULL) {
		printf("FILE IS NOT OPENED\n");
		return -1;
	}

	for (int i = 0; i < sizeof(text) - 1; i++) {
		fputc(text[i], fp);
	}

	fclose(fp);

	printf("�Է��� �Ϸ�Ǿ����ϴ�.\n");
}