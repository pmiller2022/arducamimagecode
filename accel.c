#include <stdint.h>
#include <stdio.h>

#define SAMPLES 8
#define THRESHOLD 1500

typedef struct coord {
    uint16_t x;
    uint16_t y;
    uint16_t z;
} Coordinate;


int main(void) {
      uint8_t buffer[6];
    int16_t accel_x, accel_y, accel_z;
    int16_t gyro_x, gyro_y, gyro_z;

    double prev_accel_x_avg = 0;
    double prev_accel_y_avg = 0;
    double prev_accel_z_avg = 0;

    double prev_gyro_x_avg = 0;
    double prev_gyro_y_avg = 0;
    double prev_gyro_z_avg = 0;

    Coordinate accel_data[SAMPLES];
    Coordinate gyro_data[SAMPLES];

    int is_empty =  1;
    int sample_index = 0;
    int avg_index = 0;
    int cur_accel_x_avg = 0;
    int cur_accel_y_avg = 0;
    int cur_accel_z_avg = 0;

    int cur_gyro_x_avg = 0;
    int cur_gyro_y_avg = 0;
    int cur_gyro_z_avg = 0;

       if (sample_index < SAMPLES) {
    	   (accel_data[sample_index]).x = accel_x;
    	   (accel_data[sample_index]).y = accel_y;
    	   (accel_data[sample_index]).z = accel_z;

    	   (gyro_data[sample_index]).x = gyro_x;
    	   (gyro_data[sample_index]).y = gyro_y;
    	   (gyro_data[sample_index]).z = gyro_z;

    	   sample_index++;
       } else {
    	   avg_index = 0;
    	   cur_accel_x_avg = 0;
    	   cur_accel_y_avg = 0;
    	   cur_accel_z_avg = 0;

    	   cur_gyro_x_avg = 0;
    	   cur_gyro_y_avg = 0;
    	   cur_gyro_z_avg = 0;
    		while(avg_index < SAMPLES) {
    			   cur_accel_x_avg += (accel_data[avg_index].x) / SAMPLES;
    			   cur_accel_y_avg += (accel_data[avg_index].y) / SAMPLES;
    			   cur_accel_z_avg += (accel_data[avg_index].z) / SAMPLES;

    			   cur_gyro_x_avg += (gyro_data[avg_index].x) / SAMPLES;
    			   cur_gyro_y_avg += (gyro_data[avg_index].y) / SAMPLES;
    			   cur_gyro_z_avg += (gyro_data[avg_index].z) / SAMPLES;

    			   avg_index++;
    	   }

    		if(!is_empty) {
    			//printf("Difference: %d\r\n", abs(cur_accel_x_avg - prev_accel_x_avg));
    			if(abs(cur_accel_x_avg - prev_accel_x_avg) > THRESHOLD) {
    				printf("Motion\r\n");
    			}
    			else if(abs(cur_accel_y_avg - prev_accel_y_avg) > THRESHOLD) {
					printf("Motion\r\n");
				}
    			else if(abs(cur_accel_z_avg - prev_accel_z_avg) > THRESHOLD) {
					printf("Motion\r\n");
				}
    			else if(abs(cur_gyro_x_avg - prev_gyro_x_avg) > THRESHOLD) {
					printf("Motion\r\n");
				}
    			else if(abs(cur_gyro_y_avg - prev_gyro_y_avg) > THRESHOLD) {
					printf("Motion\r\n");
				}
    			else if(abs(cur_gyro_z_avg - prev_gyro_z_avg) > THRESHOLD) {
					printf("Motion\r\n");
				}
    		} else {
    			is_empty = 0;
    		}

			prev_accel_y_avg = cur_accel_y_avg;
			prev_accel_z_avg = cur_accel_z_avg;
			prev_accel_x_avg = cur_accel_x_avg;

			prev_gyro_x_avg = cur_gyro_x_avg;
			prev_gyro_y_avg = cur_gyro_y_avg;
			prev_gyro_z_avg = cur_gyro_z_avg;

			sample_index = 0;
       }
    }