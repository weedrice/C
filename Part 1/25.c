#include <stdio.h>
#include <malloc.h>

void SortArr(int* arr, int num);
void ReadAndSortPrint(int number);

int main() {
	int num;
	fputs("�Է��� ������ ����: ", stdout);
	scanf("%d", &num);

	ReadAndSortPrint(num);
}

void SortArr(int * arr, int num) {
	int i, j, temp;

	for (i = 0; i < num - 1; i++) {
		for (j = 0; j < (num - i) - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void ReadAndSortPrint(int number) {
	int *arr;
	arr = (int*)malloc(sizeof(int)*number);
	int i;

	for (i = 0; i < number; i++) {
		printf("%d ��° �Է�: ", i + 1);
		scanf("%d", &arr[i]);
	}

	SortArr(arr, number);

	puts("�Էµ� ������ ���ĵ� ���");
	for (i = 0; i < number; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	free(arr);
}