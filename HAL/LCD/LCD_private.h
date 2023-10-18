/*
  Author:      Ehab Roshdy
  Version:     0.1
  Date:        21/8/2023
  Description: LCD driver private file

  This is the private file for the LCD driver, containing static helper functions and
  some static data variables. It is meant for internal use by the LCD driver and should
  not be directly accessed outside of the driver.

  The private functions in this file are used for sending the enable pulse to the LCD and
  setting the LCD mode. The static data variables hold information about data ports and pins
  used for the LCD configuration.

  Note: These functions and data should not be accessed or modified directly by the user
  of the LCD driver.
*/

// Declare static helper functions

// Function to send the enable pulse to the LCD
static void sendEnablePulse();

// Function to set the LCD mode (4-bit or 8-bit)
static void lcdSetMode();

static unsigned char dataPorts[4];  // Data ports for the LCD
static unsigned char dataPins[4];   // Data pins for the LCD
