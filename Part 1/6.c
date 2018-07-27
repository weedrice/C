#include <stdio.h>

int main() {
	int sum = 0;
	int temp;
	printf("정수형 데이터 입력: ");
	scanf("%d", &temp);
	sum += temp;
	int max = temp;
	int min = temp;
	for (int i = 0; i < 6; i++) {
		printf("정수형 데이터 입력: ");
		scanf("%d", &temp);
		sum += temp;
		if (temp > max)
			max = temp;
		if (min > temp)
			min = temp;
	}
	printf("최대값: %d\n", max);
	printf("최소값: %d\n", min);
	printf("전체합: %d\n", sum);
	printf("평  균: %lf\n", sum / 7.0);
}