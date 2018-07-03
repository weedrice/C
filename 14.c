#include <stdio.h>

int main() {
	int arr[5];
	for (int i = 0; i < 5; i++) {
		printf("숫자 %d 입력: ", i + 1);
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4-i; j++) {
			if (arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

	printf("정렬된 출력: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
}