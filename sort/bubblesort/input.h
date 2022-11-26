#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int val;
	char* str;
} Values;

Values* getValues (char** inputs, int count);
void printValues(Values* arr, int n);
