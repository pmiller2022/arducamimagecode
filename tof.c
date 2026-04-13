#include <stdint.h>
#include <stdlib.h>

#define SAMPLES 10
#define THRESHOLD 1000

int main(void) {
    uint16_t dist_mm;
    uint16_t tof_samp_buff[SAMPLES];
    double prev_avg = 0;
    double cur_avg = 0;
    int sample_index = 0;
    int is_empty = 1;
    int i, j;

    while(sample_index < SAMPLES) {
        tof_samp_buff[sample_index] = dist_mm;
        sample_index++;
    }

    if(sample_index == SAMPLES) {
        if (is_empty) {
            i = 0;
            while(i < SAMPLES) {
                prev_avg += tof_samp_buff[i] / SAMPLES;
                i++;
            }
            i = 0;
            is_empty = 0;
        } else {
            int j = 0;
            while(j < SAMPLES) {
                cur_avg += tof_samp_buff[j] / SAMPLES;
                j++;
            }

            if(abs(cur_avg - prev_avg) > THRESHOLD) {
                printf("Detection: ToF");
            }

            prev_avg = cur_avg;
        }
    }

}