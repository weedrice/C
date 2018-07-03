#include <stdio.h>

int main() {
	int n;
	while (1) {
		printf("홀수 단(1), 짝수 단(2): ");
		scanf("%d", &n);
		if (n != 1 || n != 2)
			printf("잘못된 입력입니다. 1 또는 2만 입력하세요.\n");
		else
			break;
	}

	for (int i = 1; i <= 9; i++) {
		if (n == 1 && i % 2 == 1) {
			for (int j = 1; j <= 9; j++) {
				printf("%d X %d = %d\n", i, j, i*j);
			}
		}
		if (n == 2 && i % 2 == 0) {
			for (int j = 1; j < 10; j++) {
				printf("%d X %d = %d\n", i, j, i*j);
			}
		}
	}
}