#include <stdio.h>

int main() {
	int n;
	printf("자연수 입력: ");
	scanf("%d", &n);
	int evensum = 0;
	int oddsum = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			evensum += i;
		}
		else {
			oddsum += i;
		}
	}
	printf("%d 이하 홀수 합: %d\n", n, oddsum);
	printf("%d 이하 짝수 합: %d\n", n, evensum);
}