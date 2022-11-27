#include "../input.h"

// concept 
    // 4 1 10 7 3
    // 
    //
void insertionSort(Values* arr, int n) {
    Values value;

    for (int cursor = 0; cursor < n - 1; cursor++) {
        int inside = cursor;
        //printf(" round %d: \n", cursor);
        while (inside >= 0 && arr[inside].val > arr[inside + 1].val) {
            //printf(" \tinside %d:\n", inside);
            value = arr[inside];
            arr[inside] = arr[inside + 1];
            arr[inside + 1] = value;
            inside--;
            //printf("\t\t");
            //printValues(arr, n);
        }
    }

    return;
}

int main(int argc, char** argv) {
    int args = argc - 1;
    Values* vArr = getValues(argv, args);

    printf("input: ");
    printValues(vArr, args);
    
    insertionSort(vArr, args);

    printf("\n");
    printf("output: ");
    printValues(vArr, args);


    free(vArr);

    return 0;
}

