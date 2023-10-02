
/*
  Author:      Ehab Roshdy                                                                      
  Version:     0.1                                                                       
  Date:        21/8/2023                                                                             
  Description: LCD driver private file                                       
*/

// Declare static helper functions
static void sendEnablePulse();              // Function to send the enable pulse to the LCD
static void lcdSetMode();

static unsigned char dataPorts[4];
static unsigned char dataPins[4];
