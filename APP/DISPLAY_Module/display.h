#ifndef DISPLAY_H_
#define DISPLAY_H_

/* Task Declarations */

// Task to display a constant string on the display.
void lcd_display_const_string(void);

// Task to manage displaying content on the screen, which may include dynamic data.
void lcd_display(void);

#endif
