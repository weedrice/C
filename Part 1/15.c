#include <stdio.h>

int main() {
	char c;
	while (1) {
		c = getchar();

		if (c == EOF)
			break;
		if (c >= '0' && c <= '9')
			printf("�Է��Ͻ� ���ڴ� �ƶ��Ƽ����Դϴ�.\n");
		else if (c >= 'a' && c <= 'z')
			printf("�Է��Ͻ� ���ڴ� ���ĺ� �ҹ����Դϴ�.\n");
		else if (c >= 'A' && c <= 'Z')
			printf("�Է��Ͻ� ���ڴ� ���ĺ� �빮���Դϴ�.\n");
		else
			printf("Ư�����ڸ� �Է��ϼ̱���.\n");

		getchar();
	}
	printf("���α׷��� �����մϴ�.\n");
}