#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int n;
	int* arr;
} DisArr;

DisArr getArray () {
	DisArr tArr; 

	printf("How many items are you entering?\n");
	scanf("%d", &tArr.n);
	tArr.arr = calloc(tArr.n, sizeof(int));

	printf("Input numbers (space seperated):\n");
	for (int a = 0; a < tArr.n; a++) {
		scanf("%d", tArr.arr + a);
	}
	
	printf("\n");

	return tArr;
}

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

void bubSort(int* arr, int n) {
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
	//int arr[] = { 10, 5, 6, 32, 12, 11, 1, 13, 4, 8 };
	DisArr nArr = getArray();

	printf("origin: ");
	printArr(nArr.arr, nArr.n);
	printf("\n");

	bubSort(nArr.arr, nArr.n); 

	return 0;
}
