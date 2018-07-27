#include <cstdio>

int main() {
	char c;
	int i;
	double d;
	char str[100];
	printf("[문자, 정수, 실수, 문자열]의 포맷으로 입력: ");
	scanf("%c, %d, %lf, %s", &c, &i, &d, &str);

	printf("입력된 데이터 출력: %c, %d, %lf, %s", c, i, d, str);
}