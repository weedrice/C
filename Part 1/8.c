#include <stdio.h>

int main() {
	int num;
	printf("10���� ���� �Է�: ");
	scanf("%d", &num);

	int answer = 0;
	int numsave = num;
	int n = 1;
	while (num > 0) {
		answer += (num % 2) * n;
		num /= 2;
		n *= 10;
	}

	printf("%d�� 2������ ��ȯ�ϸ� %d", numsave, answer);
}