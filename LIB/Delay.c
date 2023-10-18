#include "Delay.h"

// Function to create a delay in milliseconds
void delay_ms(int milliseconds) {
    int i, j;
    for (i = 0; i < milliseconds; i++) {
        for (j = 0; j < 3180; j++);
    }
}

// Function to create a delay in microseconds
void delay_us(int microseconds) {
    int i, j;
    for (i = 0; i < microseconds; i++) {
        for (j = 0; j < 3; j++);
    }
}
