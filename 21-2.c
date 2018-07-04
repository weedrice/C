#include <stdio.h>

int summation1(int (*arr)[2], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 2; j++) {
			sum += arr[i][j];
		}
	}
	return sum;
}

int summation2(int (*arr)[3], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 3; j++) {
			sum += arr[i][j];
		}
	}
	return sum;
}

int main() {
	int arr3[2][2] = { 1, 3, 5, 7 };
	int arr4[2][3] = { 1, 2, 3, 4, 5, 6 };
	printf("1, 3, 5, 7의 합: %d\n", summation1(arr3, 2));
	printf("1, 2, 3, 4, 5, 6의 합: %d\n", summation2(arr4, 2));
}