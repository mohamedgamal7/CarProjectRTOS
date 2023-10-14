#include "Delay.h"


void delay_ms(int m){
    int i, j;
    for(i = 0; i < m; i++){
        for(j = 0; j < 3180; j++);
    }
}
void delay_us(int m){
    int i, j;
    for(i = 0; i < m; i++){
        for(j = 0; j < 3; j++);
    }
}
