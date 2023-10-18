#ifndef ADC_H__
#define ADC_H__

#include <stdbool.h>
#include "MCAL/ADC/ADC_Types.h"

#define SYSCTL_RCGCADC_R        (*((volatile unsigned long *)0x400FE638))

#define ADC0_Reg (((volatile ADC_RegType *)0x40038000))
#define ADC1_Reg (((volatile ADC_RegType *)0x40039000))

/*******************Active Sample Sequencer********************/

#define ASEN0 (1<<0)  // Active Sample Sequencer 0
#define ASEN1 (1<<1)  // Active Sample Sequencer 1
#define ASEN2 (1<<2)  // Active Sample Sequencer 2
#define ASEN3 (1<<3)  // Active Sample Sequencer 3
#define BUSY  (1<<16) // ADC Busy Flag

/****************************Int Mask*****************************/

#define MASK0 (1<<0)  // Mask for Interrupt 0
#define MASK1 (1<<1)  // Mask for Interrupt 1
#define MASK2 (1<<2)  // Mask for Interrupt 2
#define MASK3 (1<<3)  // Mask for Interrupt 3

#define DCONSS0 (1<<16) // Digital Comparator Output Selection for Sample Sequencer 0
#define DCONSS1 (1<<17) // Digital Comparator Output Selection for Sample Sequencer 1
#define DCONSS2 (1<<18) // Digital Comparator Output Selection for Sample Sequencer 2
#define DCONSS3 (1<<19) // Digital Comparator Output Selection for Sample Sequencer 3

/******************************Int Clr********************************/

#define IN0 (1<<0)  // Clear Interrupt 0
#define IN1 (1<<1)  // Clear Interrupt 1
#define IN2 (1<<2)  // Clear Interrupt 2
#define IN3 (1<<3)  // Clear Interrupt 3

/*******************************Event MUX****************************/

#define PROCESSOR (0x0U)  // Processor Trigger
#define COMP0     (0x1U)  // Comparator 0
#define COMP1     (0x2U)  // Comparator 1
#define GPIOEX    (0x4U)  // GPIO Event X
#define TIMER     (0x5U)  // Timer
#define PWM0      (0x6U)  // PWM Generator 0
#define PWM1      (0x7U)  // PWM Generator 1
#define PWM2      (0x8U)  // PWM Generator 2
#define PWM3      (0x9U)  // PWM Generator 3
#define ALWAYS    (0xFU)  // Always (Continuously Sample)
#define WHEN_REQUIRED (0x0U)  // Event Mux Disabled

/*******************************PRIORITY******************************/

#define PR_0  (0x0U)  // Priority 0
#define PR_1  (0x1U)  // Priority 1
#define PR_2  (0x2U)  // Priority 2
#define PR_3  (0x3U)  // Priority 3

/******************************HW OverSampling*************************/

#define   NoHWSAMPLING  0x0  // No Hardware Oversampling
#define   HWSAMPLING2x  0x1  // 2x Hardware Oversampling
#define   HWSAMPLING4x  0x2  // 4x Hardware Oversampling
#define   HWSAMPLING8x  0x3  // 8x Hardware Oversampling
#define   HWSAMPLING16x 0x4  // 16x Hardware Oversampling
#define   HWSAMPLING32x 0x5  // 32x Hardware Oversampling
#define   HWSAMPLING64x 0x6  // 64x Hardware Oversampling

/******************************DIGITAL Comp clr********************************/

#define DCINT0  (1<<0)  // Clear Digital Comparator Interrupt 0
#define DCINT1  (1<<1)  // Clear Digital Comparator Interrupt 1
#define DCINT2  (1<<2)  // Clear Digital Comparator Interrupt 2
#define DCINT3  (1<<3)  // Clear Digital Comparator Interrupt 3
#define DCINT4  (1<<4)  // Clear Digital Comparator Interrupt 4
#define DCINT5  (1<<5)  // Clear Digital Comparator Interrupt 5
#define DCINT6  (1<<6)  // Clear Digital Comparator Interrupt 6
#define DCINT7  (1<<7)  // Clear Digital Comparator Interrupt 7

/********************************Channels**********************************/

#define AIN0  (0U)  // Analog Input Channel 0 (E3)
#define AIN1  (1U)  // Analog Input Channel 1 (E2)
#define AIN2  (2U)  // Analog Input Channel 2 (E1)
#define AIN3  (3U)  // Analog Input Channel 3 (E0)
#define AIN4  (4U)  // Analog Input Channel 4 (D3)
#define AIN5  (5U)  // Analog Input Channel 5 (D2)
#define AIN6  (6U)  // Analog Input Channel 6 (D1)
#define AIN7  (7U)  // Analog Input Channel 7 (D0)
#define AIN8  (8U)  // Analog Input Channel 8 (E5)
#define AIN9  (9U)  // Analog Input Channel 9 (E4)
#define AIN10 (10U) // Analog Input Channel 10 (B4)
#define AIN11 (11U) // Analog Input Channel 11 (B5)

/********************************Sampler************************************/

#define SAMPLER0  (0U)  // Sample Sequencer 0
#define SAMPLER1  (1U)  // Sample Sequencer 1
#define SAMPLER2  (2U)  // Sample Sequencer 2
#define SAMPLER3  (3U)  // Sample Sequencer 3

/********************************ADC***************************/

#define ADC0 (0U)  // ADC 0
#define ADC1 (1U)  // ADC 1

#include <stdbool.h>

/*************************************FUNCS Prototypes*************************************/

// Check if the ADC is busy
bool ADCBusy(uint32 ui32ADC);

// Initialize the ADC for usage
void ADCStartUse(uint32 ui32ADC);

// Initialize a sampler in the ADC
void ADCInitSampler(uint32 ui32ADC, uint32 ui32Sampler, uint32 Event, uint32 ui32Channel);

// Assign a channel to a sampler
void ADCAssignChannel(uint32 ui32ADC, uint32 ui32Sampler, uint32 ui32Channel);

// Read the ADC value from a specific sampler
int32 ADCRead(uint32 ui32ADC, uint32 ui32Sampler);

// Enable temperature sensor input
void ADCTempEnable(uint32 ui32ADC, uint32 ui32Sampler);

// Clear ADC interrupt
void ADCIntClear(uint32 ui32ADC, uint32 ui32SequenceNum);

// Disable ADC interrupt
void ADCIntDisable(uint32 ui32ADC, uint32 ui32SequenceNum);

// Enable ADC interrupt
void ADCIntEnable(uint32 ui32ADC, uint32 ui32SequenceNum);

// Register a callback function for ADC interrupt
void ADCIntRegister(uint32 ui32ADC, uint32 ui32SequenceNum, void (*pfnHandler)(void));

// Check the status of ADC interrupt
uint32 ADCIntStatus(uint32 ui32ADC, uint32 ui32SequenceNum, bool bMasked);

#endif
