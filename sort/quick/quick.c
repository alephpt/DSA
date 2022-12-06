#include "../input.h"

void bubbleSort(Values* arr, int n) {
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++) {
			if (arr[j].val > arr[j + 1].val) {
				swapValues(&arr[j], &arr[j + 1]);
			}
		}
	}
}

int quickPart (Values* arr, int l, int r) {
    //Values* pivot = &arr[random() % r];
    Values pivot = arr[r];
    printf("\tpivot: %d\n", pivot.val);
    
    int i = l - 1;

    for (int j = l; j <= r - 1; j++) {
        if (arr[j].val < pivot.val) {
            printf(" - if j.%d < pivot.%d\n", arr[j].val, pivot.val);
            printf("\tswapping %d: i=%d <-> j=%d\n", i, arr[i].val, arr[j].val);
            swapValues(&arr[++i], &arr[j]);
        }
    }

    printf("\tswapping %d: i+1=%d <-> r=%d\n", i, arr[i + 1].val, arr[r].val);

    swapValues(&arr[++i], &arr[r]);
    
    printf("\treturning: %d\n", i);
    return (i);
}

void quickSort (Values* arr, int l, int r) {
    printf("starting l-%d r-%d\n", l, r);
    
    if (l < r) {
        printf(" - quickpart(l:%d, r:%d)\n", l, r);
        int parti = quickPart(arr, l, r);
        printf(" - quickpart(l:%d, r:%d) -> parti:%d\n", l, r, parti);

        printf(" - quickSort(l:%d, parti-1:%d)\n", l, parti - 1);
        quickSort(arr, l, parti - 1);
        printf(" - quickSort(parti+1:%d, r%d)\n", parti+1, r);
        quickSort(arr, parti + 1, r);
    } else {
        printf ("\t - %d > %d\n", l, r);
    }

    printf("ending l-%d r-%d\n", l, r);
}

int main(int argc, char** argv) {
	Values* nArr = getValues(argv, argc - 1);

	printf("input: ");
	printf("\n");
	printValues(nArr, argc - 1);
	printf("\n");

	quickSort(nArr, 0, argc - 1); 

	printf("sorted: ");
	printf("\n");
	printValues(nArr, argc - 1);
	printf("\n");
	
	free(nArr);

	return 0;
}
