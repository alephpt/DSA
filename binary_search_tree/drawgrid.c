#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

const int layers = 5;                                           // number of layers
const int canvas = layers * 7;                                          // size of canvas
const int h = canvas;                                           // pass canvas to height
const int w = (int)(canvas * 2.3);                              // scale canvas to width for ascii scaling

void print_canvas(int width, int height) {
    int h_offset = 0;
    int sub_x_count = 0;
    int sub_y_count = 0;
    int branches = 0;
    int branch_offset = 0;
    
    for (int y = layers; y < height; y++)                            // for each row
    {
        int v_offset = (int)((h / layers) / (sub_y_count + 1));     // vertical offset is the height / layers / sub_y
        int y_row_offset = y + (int)(v_offset * 0.5);               // row offset is half the vertical offset
        sub_x_count = 0;                                            // reset x

        for (int x = 0; x < width; x++)                             // for each column
        {
            if (sub_y_count < layers &&                             // if the y count < total layers
                y_row_offset % v_offset == 0)                       // and if the row - 1/2 offset % total offset
            {                           
                if(x == width / 2 &&                                // if x is 1/2 width &&
                   sub_y_count == 0)                                // we're on the first row
                {                                                                  
                    printf("%d", sub_y_count);                      // print the number in the middle
                } else 
                if (sub_x_count < branches &&                       // if the subdivision counter is less than the branches
                    (x - branch_offset) % h_offset == 0)            // and the x less the offset % the branches subdivisions = 0
                {                                   
                    printf("%d", sub_y_count);                      // print the number
                    sub_x_count++;                                  // and increase the subdivisions counter
                } else 
                {
                    printf(" ");
                }
            } 
            else 
            {
                printf(" ");
            }
        }
 
        if (y_row_offset % v_offset == 0) 
        {
            sub_y_count++;
            branches = pow(2, sub_y_count);
            h_offset = (int)w /branches;
            branch_offset = (int)(h_offset * 0.5);

            if (sub_y_count > layers) {
                return;
            }
        }
        printf("\n");
    }
    return;
}

int main () {
    print_canvas(w, h);

    return 0;
}
