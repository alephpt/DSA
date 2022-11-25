#include <stdio.h>

void swap(int* primera, int* segundo) {
	int first = *primera;
	*primera = *segundo;
	*segundo = first;

	return;
}

void printArr(int arr[], int n) {

	for(int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");

	return;
}

void bubSort(int arr[], int n) {
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++) {
		//	printf("i-%d : j-%d\n", i, j);

			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}

			printf("pass %d, phase %d: ", i, j);
			printArr(arr, n);
		}
	}
}

int main() {
	int arr[] = { 10, 5, 6, 32, 12, 11, 1, 13, 4, 8 };

	printf("origin: ");
	printArr(arr, sizeof(arr) / sizeof(arr[0]));
	printf("\n\n");

	bubSort(arr, sizeof(arr) / sizeof(arr[0]));

	return 0;
}
