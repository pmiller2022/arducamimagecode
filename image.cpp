#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 320
#define HEIGHT 240
#define IMAGE_THRESHOLD 1000
#define PIXEL_THRESHOLD 50

void rand_frames(uint8_t f1[HEIGHT][WIDTH], uint8_t f2[HEIGHT][WIDTH]){
    srand(time(NULL));

    int i = 0;
    int j = 0;
    uint8_t rnd;
    while(i < HEIGHT) {
        while(j < WIDTH) {
            rnd = rand() % 256;
            f1[i][j] = rnd;

            rnd = rand() % 256;
            f2[i][j] = rnd;

            j++;
        }
        i++;
        j = 0;
    }
}



int main(void) {
    uint8_t frame1[HEIGHT][WIDTH];
    uint8_t frame2[HEIGHT][WIDTH];
    bool pixel_thres[HEIGHT][WIDTH];

    // Replace with camera stuff
    rand_frames(frame1, frame2);
    
    uint64_t diff_sum = 0;
    int i = 0;
    int j = 0;
    while(i < HEIGHT) {
        while(j < WIDTH) {
            if (frame1[i][j] >= frame2[i][j]) {
                diff_sum += frame1[i][j] - frame2[i][j];

                pixel_thres[i][j] = (frame1[i][j] - frame2[i][j]) > PIXEL_THRESHOLD;
                
            } else {
                diff_sum += frame2[i][j] - frame1[i][j];

                pixel_thres[i][j] = (frame2[i][j] - frame1[i][j]) > PIXEL_THRESHOLD;
            }
            j++;
        }
        i++;
        j = 0;
    }

    printf("%llu\n", diff_sum);

    if (diff_sum > IMAGE_THRESHOLD) {
        printf("Movement\n");
    }
}