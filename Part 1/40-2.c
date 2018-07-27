#include <stdio.h>
#include <string.h>

int main() {
	char original[100];
	char copy[100];

	FILE *fp_ori;
	FILE *fp_cop;

	printf("���� �̸�: ");
	gets(original);
	printf("���纻 �̸�: ");
	gets(copy);

	fp_ori = fopen(original, 'rb');
	fp_cop = fopen(copy, 'wb');

	if (fp_ori == NULL) {
		printf("FILE IS NOT OPENED\n");
		return -1;
	}
	if (fp_cop == NULL) {
		printf("FILE IS NOT OPENED\n");
		return -1;
	}

	int i = 0;
	while (i != EOF) {
		i = fgetc(fp_ori);
		fputc(i, fp_cop);
	}

	printf("���簡 �Ϸ�Ǿ����ϴ�.\n");
	fclose(fp_ori);
	fclose(fp_cop);
}