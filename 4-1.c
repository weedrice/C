#include <stdio.h>

int main(void) {
	int n=0;
	char c;

	while (1) {
		fputs("Data input (Ctrl+Z to exit): ", stdout);
		c = getchar();
		if (c == EOF)
			break;
		getchar();
		n++;
	}

	printf("�Էµ� ������ ��: %d\n", n);
}