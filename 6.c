#include <stdio.h>

int main() {
	int sum = 0;
	int temp;
	printf("������ ������ �Է�: ");
	scanf("%d", &temp);
	sum += temp;
	int max = temp;
	int min = temp;
	for (int i = 0; i < 6; i++) {
		printf("������ ������ �Է�: ");
		scanf("%d", &temp);
		sum += temp;
		if (temp > max)
			max = temp;
		if (min > temp)
			min = temp;
	}
	printf("�ִ밪: %d\n", max);
	printf("�ּҰ�: %d\n", min);
	printf("��ü��: %d\n", sum);
	printf("��  ��: %lf\n", sum / 7.0);
}