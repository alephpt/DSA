#include "input.h"

void swapValues (Values* primera, Values* segundo) {
	Values first = *primera;
	*primera = *segundo;
	*segundo = first;

	return;
}

void bubbleSort(Values* arr, int n) {
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++) {
			if (arr[j].val > arr[j + 1].val) {
				swapValues(&arr[j], &arr[j + 1]);
			}
		}
	}
}

int main(int argc, char** argv) {
	Values* nArr = getValues(argv, argc - 1);

	printf("input: ");
	printf("\n");
	printValues(nArr, argc - 1);
	printf("\n");

	bubbleSort(nArr, argc - 1); 

	printf("sorted: ");
	printf("\n");
	printValues(nArr, argc - 1);
	printf("\n");
	
	free(nArr);

	return 0;
}
