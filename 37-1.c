#include <stdio.h>

int main() {
	FILE *fp = fopen("37-1.txt", "wb");
	if (fp == NULL) {
		printf("FILE IS NOT OPENED\n");
		return -1;
	}

	int n;
	for (int i = 0; i < 5; i++) {
		printf("���Ͽ� ������ ���� %d: ", i + 1);
		scanf("%d", &n);
		fwrite(&n, sizeof(int), 1, fp);
	}

	fclose(fp);
	printf("�Է��� �Ϸ�Ǿ����ϴ�.\n");
}