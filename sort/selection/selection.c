#include "../input.h"

void selectionSort(Values* arr, int n) {
    int bounds, item, min_idx;

    for (bounds = 0; bounds < n - 1; bounds++) {
        min_idx = bounds;
        
        for (item = bounds + 1; item < n; item++) {
            if (arr[item].val < arr[min_idx].val) {
                min_idx = item;
            }
        }
         
        if (min_idx != bounds) {
            swapValues(&arr[min_idx], &arr[bounds]); 
            
            printf("bounds: %d - ", bounds, item);
            printValues(arr, n);
        }
    }

    return;
}

int main(int argc, char** argv) {
    int args = argc - 1;
    Values* vArr = getValues(argv, args);

    printf("input: ");
    printValues(vArr, args);
    printf("\n");
    
    selectionSort(vArr, args);

    printf("\n");
    printf("output: ");
    printValues(vArr, args);


    free(vArr);

    return 0;
}
