#include <stdio.h>

int main() {
	double radius;
	printf("반지름 입력: ");
	scanf("%lf", &radius);
	printf("원의 넓이: %lf", radius * radius * 3.14);
}