#include <stdio.h>

int summation(int* arr, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum;
}

int main() {
	int arr1[3] = { 5, 10, 15 };
	int arr2[5] = { 1, 2, 3, 4, 5 };
	printf("5, 10, 15�� ��: %d\n", summation(arr1, 3));
	printf("1, 2, 3, 4, 5�� ��: %d\n", summation(arr2, 5));
}