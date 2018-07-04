#include <stdio.h>

int factorial(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}

int main() {
	int n;
	printf("숫자 입력(1이상): ");
	scanf("%d", &n);

	printf("%d! = %d\n", n, factorial(n));
}