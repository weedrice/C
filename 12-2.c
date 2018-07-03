#include <stdio.h>

int main() {
	int n;
	printf("정수 입력: ");
	scanf("%d", &n);
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			for (int k = 0; k < 101; k++) {
				if (i*j - k == n) {
					printf("%d X %d - %d = %d\n", i, j, k, n);
				}
			}
		}
	}
}