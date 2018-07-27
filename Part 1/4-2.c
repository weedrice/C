#include <stdio.h>

int main() {
	int total = 0;
	int input = 0;
	int ret;

	while (1) {
		printf("Data input (Ctrl+Z to exit): ");
		ret = scanf("%d", &input);
		if (ret == EOF)
			break;
		total += input;
	}

	printf("ÃÑ ÇÕ: %d\n", total);
}