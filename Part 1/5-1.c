#include <stdio.h>

int main() {
	double a, b;
	printf("µÎ °³ÀÇ ½Ç¼ö ÀÔ·Â: ");
	scanf("%lf %lf", &a, &b);
	printf("µ¡¼À °á°ú: %lf\n", a + b);
	printf("»¬¼À °á°ú: %lf\n", a - b);
	printf("°ö¼À °á°ú: %lf\n", a * b);
	printf("³ª´°¼À °á°ú: %lf\n", a / b);
}