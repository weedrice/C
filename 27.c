#include <stdio.h>

int main() {
	char title[3][20];
	char publish[3][20];
	int price[3];
	printf("********* ���� ���� �Է� *********\n");
	for (int i = 0; i < 3; i++) {
		printf("%d��° ���� ���� �Է�.\n", i + 1);
		printf("���� ����: ");
		gets(title[i]);
		printf("���ǻ� ��: ");
		gets(publish[i]);
		printf("���� ����: ");
		scanf("%d", &price[i]);
		getchar();
		printf("%d��° �Է� �Ϸ�.......\n", i + 1);
	}
	printf("********* ���� ���� ��� *********\n");
	for (int i = 0; i < 3; i++) {
		printf("%d��° ���� ���� ���.\n", i + 1);
		printf("���� ����: %s\n", title[i]);
		printf("���ǻ� ��: %s\n", publish[i]);
		printf("���� ����: %d\n", price[i]);
	}
}