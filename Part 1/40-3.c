#include <stdio.h>
#include <string.h>

int main() {
	char original[100];
	char copy[100];
	char buff[100];
	int buffCnt;

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

	while (1) {
		buffCnt = fread(buff, 1, 100, fp_ori);
		if (buffCnt < 100) {
			if (feof(fp_ori != 0)) {
				break;
			}
			else {
				printf("���� �߻�! ���縦 �Ϸ����� ���߽��ϴ�.\n");
				return -1;
			}
		}
		fwrite(buff, 1, buffCnt, fp_cop);
	}

	printf("���簡 �Ϸ�Ǿ����ϴ�.\n");
	fclose(fp_ori);
	fclose(fp_cop);
}