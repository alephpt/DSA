#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int layers = 7;
int layer_cnt = 1;
int horiz_center = 0;
int verti_center = 0;
int sub_count = 0;

int layer_offset() {
    if (layer_cnt == 1) {
        return layer_cnt;
    }
    return 
}

void print_canvas(int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if ((x == width / 2) || 
                (y == height / 2)) {
                printf("x");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }

    return;
}

int main () {
    int canvas = 25; 
    int height = canvas; 
    int width = (int)(canvas * 2.3);
    horiz_center = width / (layer_cnt * 2);
    verti_center = width / layers;
    
    printf("horizontal: %d\n", horiz_center);
    printf("vertical: %d\n", verti_center);
    printf("\n");

    print_canvas(width, height);

    return 0;
}

