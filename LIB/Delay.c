#include "Delay.h"

/**
 * @brief Delay for the specified number of milliseconds.
 *
 * @param m The number of milliseconds to delay.
 */
void delay_ms(int m) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < 3180; j++);
    }
}

/**
 * @brief Delay for the specified number of microseconds.
 *
 * @param m The number of microseconds to delay.
 */
void delay_us(int m) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < 3; j++);
    }
}
