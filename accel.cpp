#include <stdint.h>

#define SAMPLES 10

typedef struct coord {
    uint16_t x;
    uint16_t y;
    uint16_t z;
} Coordinate;

bool is_empty = true;

Coordinate prev_accel_data[SAMPLES];
Coordinate prev_gyro_data[SAMPLES];

double average(Coordinate* points) {
    
}

int process_accel() {
    Coordinate cur_accel_data[SAMPLES];
    Coordinate cur_gyro_data[SAMPLES];

    int i = 0;
    while (i < SAMPLES) {
        // TODO: Grab next accel and gyro values 
        Coordinate accel;
        Coordinate gyro;

        cur_accel_data[i].x = accel.x;
        cur_accel_data[i].y = accel.y;
        cur_accel_data[i].z = accel.z;

        cur_gyro_data[i].x = gyro.x;
        cur_gyro_data[i].y = gyro.y;
        cur_gyro_data[i].z = gyro.z;

        // Run some averaging from each 


        prev_accel_data[i].x = accel.x;
        prev_accel_data[i].y = accel.y;
        prev_accel_data[i].z = accel.z;

        prev_gyro_data[i].x = gyro.x;
        prev_gyro_data[i].y = gyro.y;
        prev_gyro_data[i].z = gyro.z;

        i++;
    }
}

int main(void) {
    process_accel();
}