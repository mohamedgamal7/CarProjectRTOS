#ifndef _APP_H
#define _APP_H

// Define time periods for various operations or checks
#define ULTRASONIC_PERIOD       60      // Ultrasonic sensor operation/check period (milliseconds)
#define LCD_PERIOD              200     // LCD-related operation/check period (milliseconds)
#define BUTTON_CHECK_PERIOD     80      // Button state check/handling period (milliseconds)
#define LDR_PERIOD              100     // Light-dependent resistor (LDR) operation/check period (milliseconds)
#define TEMP_PERIOD             150     // Temperature-related operation/check period (milliseconds)

// Enumeration to represent car states
typedef enum
{
    free_running,           // Car is in a free-running state
    blocked_reverse,        // Car is blocked and needs to reverse
    blocked_turning         // Car is blocked and needs to turn
} car_state;

#endif
