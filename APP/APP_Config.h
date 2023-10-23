
#ifndef _APP_H
#define _APP_H


#define ULTRASONIC_PERIOD       60
#define LCD_PERIOD              200
#define BUTTON_CHECK_PERIOD     80
#define LDR_PERIOD              100
#define TEMP_PERIOD             150
#define STEERING_PERIOD         120


typedef enum
{
    free_running,
    blocked_reverse,
    blocked_turning
} car_state;

#define PbConfigAddress  (const uint32_t *)0x00008000





#endif
