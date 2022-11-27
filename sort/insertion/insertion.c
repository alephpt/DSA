#include "../input.h"

void insertionSort(Values* arr, int n) {
    int idx, prev_i;
    Values key;

    for (idx = 1; idx < n; idx++) {
        Values key = arr[idx];
        prev_i = idx - 1;
        printf("\nfor %d: \n", idx);
        while (prev_i >= 0 && arr[prev_i].val > key.val) {
            printf("\twhile %d\n\t", prev_i);
            arr[prev_i + 1] = arr[prev_i];
            prev_i = prev_i - 1;
            printValues(arr, n);
        }
        arr[prev_i + 1] = key;
        printf("post for %d: \n\t", idx);
        printValues(arr, n);
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

