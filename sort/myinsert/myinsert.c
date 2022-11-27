#include "../input.h"

// concept 
    // 4 1 10 7 3
    
void insertionSort(Values* arr, int n) {
    Values target;

    // 0, 1, 2, 3, 4
    for (int cursor = 0; cursor < n - 1; cursor++) {
        int target_i = cursor + 1;

        printf("round %d: ", cursor);
        printValues(arr, n);

        if (arr[target_i - 1].val > arr[target_i].val) {
            target = arr[target_i];
            
            while(arr[target_i - 1].val > target.val && target_i > 0) {
                arr[target_i] = arr[target_i - 1];
                target_i--;
                printf("  inner %d:\n\t", target_i);
                printValues(arr, n);
            }
            
            arr[target_i] = target;
        }
 
        printf("end round %d: ", cursor);
        printValues(arr, n);
        printf("\n");   
    }

    return;
}

int main(int argc, char** argv) {
    int args = argc - 1;
    Values* vArr = getValues(argv, args);

    printf("input: ");
    printValues(vArr, args);
    printf("\n");
    
    insertionSort(vArr, args);

    printf("output: ");
    printValues(vArr, args);


    free(vArr);

    return 0;
}

