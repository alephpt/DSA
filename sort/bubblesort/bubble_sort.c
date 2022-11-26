#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	int n;
	int* arr;
	char* str[];
} DisArr;

DisArr* getArray (char** inputs, int count) {
	DisArr *tArr = malloc(sizeof(DisArr) + (sizeof(inputs) * sizeof(char)) + (count * sizeof(int))); 
	tArr->arr = malloc(count * sizeof(int));
	tArr->n = count;

	// iterate through all of the inputs
	for (int i = 1; i <= count; i++) {
		int input_int = 0; 	// interger value of input char
		int ischar = 0;   	// bool for if non-digit char

		// loop through all characters of input
		for (int l = 0; l < strlen(inputs[i]); l++) {
			// if we have not found non-digit char
			if (ischar == 0) {
				// check if it is a non-digit
				if (!isdigit(inputs[i][l])) {
					// set bool and restart count
					ischar = 1;
					l = 0;
				}
			// if we have found a non-digit char
			} else {
				// add the ascii value  
				input_int += (int)inputs[i][l];
			}
		}

		// if we did not find a non-digit char convert string to int
		if (ischar == 0) { input_int = atoi(inputs[i]); }

		// store the string and the int version
		tArr->str[i - 1] = (char*) malloc(sizeof(inputs[i - 1]));
		strcpy(tArr->str[i - 1], inputs[i]);
		tArr->arr[i - 1] = input_int;
		
		// printf("assigning \'%s\' with ASCII value %d\n", tArr->str[i - 1], input_int);
	}

	printf("\n");

	return tArr;
}

void swap(int* primeraA, char* primeraC[], int* segundoA, char* segundoC[]) {
	int firstA = *primeraA;

	size_t primC_len = strlen(*primeraC);
	char *firstC = malloc(primC_len + 2);
	firstC = *primeraC;
	
	*primeraA = *segundoA;
	*primeraC = *segundoC;
	*segundoA = firstA;
	*segundoC = firstC;

	return;
}

void printArr(int arr[], char* str[], int n) {

	for(int i = 0; i < n; i++) {
		if (atoi(*(str + i)) == arr[i]) {
			printf("%d ", arr[i]);
		} else {
			printf("%s ", str[i]);
		}
	}

	printf("\n");

	return;
}

void bubSort(int* arr, char* str[], int n) {
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &str[j], &arr[j + 1], &str[j + 1]);
			}

			printf("pass %d, phase %d: ", i, j);
			printArr(arr, str, n);
		}
	}
}

int main(int argc, char** argv) {
	//int arr[] = { 10, 5, 6, 32, 12, 11, 1, 13, 4, 8 };
	DisArr* nArr = getArray(argv, argc - 1);

//	printf("origin: ");
//	printArr(nArr->arr, nArr->str, argc - 1);
//	printf("\n");

	bubSort(nArr->arr, nArr->str, argc - 1); 

	free(nArr);

	return 0;
}
