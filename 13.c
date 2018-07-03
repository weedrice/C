#include <stdio.h>

int main() {
	int n;
	int ret;
	
	while (1) {
		printf("1 이상의 정수 입력: ");
		ret = scanf("%d", &n);

		if (ret == EOF)
			break;
		else if (n < 1)
			printf("1 이상의 입력을 필요로 합니다. 다시 입력하세요.\n");
		else {
			printf("%d의 약수들\n", n);
			for (int i = 1; i <= n; i++) {
				if (n % i == 0)
					printf("%d ", i);
			}
			printf("\n");
		}
	}
	printf("EOF 입력에 의해 프로그램을 종료합니다.\n");
}