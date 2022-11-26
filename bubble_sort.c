#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int n;
	int* arr;
} DisArr;

DisArr* getArray (char** inputs, int count) {
	DisArr *tArr = malloc(sizeof(DisArr)); 
	tArr->arr = malloc(count * sizeof(int));
	tArr->n = count;

	for (int i = 1; i <= count; i++) {
		int input_int = 0;
		if (atoi(inputs[i]) == 0) {
			for (int l = 0; l < sizeof(inputs[i]); l++) {
				input_int += (int)inputs[i][l];
			}
		}
		else {
			input_int = atoi(inputs[i]);
		}

		tArr->arr[i - 1] = input_int;
	}

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

int main(int argc, char** argv) {
	//int arr[] = { 10, 5, 6, 32, 12, 11, 1, 13, 4, 8 };
	DisArr* nArr = getArray(argv, argc - 1);

	printf("origin: ");
	printArr(nArr->arr, nArr->n);
	printf("\n");

	bubSort(nArr->arr, nArr->n); 

	free(nArr);

	return 0;
}