#include "../input.h"

void merge(Values* arr, int l, int m, int r) {
    int i, j, k;
    int len_l = m - l + 1;  // 0th to middle
    int len_r = r - m;      // middle to end

    Values Larr[len_l], Rarr[len_r];

    for (i = 0; i < len_l; i++) { Larr[i] = arr[l + i]; }
    for (j = 0; j < len_r; j++) { Rarr[j] = arr[m + j + 1]; }

    i = j = 0; 
    k = l;

    // copy items from both lists based on min
    while (i < len_l && j < len_r) {
        if (Larr[i].val <= Rarr[j].val) {
            arr[k] = Larr[i++];
        } else {
            arr[k] = Rarr[j++]; 
        }
        k++;
    }

    // push remainder of both arrays if there are any
    while (i < len_l) { arr[k++] = Larr[i++]; }
    while (j < len_r) { arr[k++] = Rarr[j++]; }
}

void mergeSort(Values* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l)/ 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
    return;
}

int main(int argc, char** argv) {
    int args = argc - 1;
    Values* vArr = getValues(argv, args);

    printf("input: ");
    printValues(vArr, args);
    
    mergeSort(vArr, 0, args - 1);

    printf("output: ");
    printValues(vArr, args);


    free(vArr);

    return 0;
}

