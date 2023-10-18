#ifndef ADC_TYPES_H__
#define ADC_TYPES_H__

#include "LIB/types.h"

// Define the structure for ADC registers
typedef struct {
    volatile uint32 ADCACTSS;     // ADC Active Sample Sequencer
    volatile uint32 ADCRIS;       // ADC Raw Interrupt Status
    volatile uint32 ADCIM;        // ADC Interrupt Mask
    volatile uint32 ADCISC;       // ADC Interrupt Status and Clear
    volatile uint32 ADCOSTAT;     // ADC Overflow Status
    volatile uint32 ADCEMUX;      // ADC Event Multiplexer Select
    volatile uint32 ADCUSTAT;     // ADC Underflow Status
    volatile uint32 ADCTSSEL;     // ADC Trigger Source Select
    volatile uint32 ADCSSPRI;     // ADC Sample Sequencer Priority
    volatile uint32 ADCSPC;       // ADC Sample Phase Control
    volatile uint32 ADCPSSI;      // ADC Processor Sample Sequence Initiate
    volatile uint32 RES1;         // Reserved
    volatile uint32 ADCSAC;       // ADC Sample Averaging Control
    volatile uint32 ADCDCISC;     // ADC Digital Comparator Interrupt Status and Clear
    volatile uint32 ADCCTL;       // ADC Control
    volatile uint32 RES2;         // Reserved
    volatile uint32 ADCSSMUX0;    // ADC Sample Sequencer Input Multiplexer Select 0
    volatile uint32 ADCSSCTL0;    // ADC Sample Sequencer Control 0
    volatile uint32 ADCSSFIFO0;   // ADC Sample Sequencer Result FIFO 0
    volatile uint32 ADCSSFSTAT0;  // ADC Sample Sequencer FIFO Status 0
    volatile uint32 ADCSSOP0;     // ADC Sample Sequencer Operation 0
    volatile uint32 ADCSSDC0;     // ADC Sample Sequencer Digital Comparator Select 0
    volatile uint32 RES3;         // Reserved
    volatile uint32 RES4;         // Reserved
    volatile uint32 ADCSSMUX1;    // ADC Sample Sequencer Input Multiplexer Select 1
    volatile uint32 ADCSSCTL1;    // ADC Sample Sequencer Control 1
    volatile uint32 ADCSSFIFO1;   // ADC Sample Sequencer Result FIFO 1
    volatile uint32 ADCSSFSTAT1;  // ADC Sample Sequencer FIFO Status 1
    volatile uint32 ADCSSOP1;     // ADC Sample Sequencer Operation 1
    volatile uint32 ADCSSDC1;     // ADC Sample Sequencer Digital Comparator Select 1
    volatile uint32 RES5;         // Reserved
    volatile uint32 RES6;         // Reserved
    volatile uint32 ADCSSMUX2;    // ADC Sample Sequencer Input Multiplexer Select 2
    volatile uint32 ADCSSCTL2;    // ADC Sample Sequencer Control 2
    volatile uint32 ADCSSFIFO2;   // ADC Sample Sequencer Result FIFO 2
    volatile uint32 ADCSSFSTAT2;  // ADC Sample Sequencer FIFO Status 2
    volatile uint32 ADCSSOP2;     // ADC Sample Sequencer Operation 2
    volatile uint32 ADCSSDC2;     // ADC Sample Sequencer Digital Comparator Select 2
    volatile uint32 RES[2];       // Reserved
    volatile uint32 ADCSSMUX3;    // ADC Sample Sequencer Input Multiplexer Select 3
    volatile uint32 ADCSSCTL3;    // ADC Sample Sequencer Control 3
    volatile uint32 ADCSSFIFO3;   // ADC Sample Sequencer Result FIFO 3
    volatile uint32 ADCSSFSTAT3;  // ADC Sample Sequencer FIFO Status 3
    volatile uint32 ADCSSOP3;     // ADC Sample Sequencer Operation 3
    volatile uint32 ADCSSDC3;     // ADC Sample Sequencer Digital Comparator Select 3
    volatile uint32 RESS[312];    // Reserved
    volatile uint32 ADCDCRIC;     // ADC Digital Comparator Reset Initial Conditions
    volatile uint32 RESSS[63];    // Reserved
    volatile uint32 ADCDCCTL0;    // ADC Digital Comparator Control 0
    volatile uint32 ADCDCCTL1;    // ADC Digital Comparator Control 1
    volatile uint32 ADCDCCTL2;    // ADC Digital Comparator Control 2
    volatile uint32 ADCDCCTL3;    // ADC Digital Comparator Control 3
    volatile uint32 ADCDCCTL4;    // ADC Digital Comparator Control 4
    volatile uint32 ADCDCCTL5;    // ADC Digital Comparator Control 5
    volatile uint32 ADCDCCTL6;    // ADC Digital Comparator Control 6
    volatile uint32 ADCDCCTL7;    // ADC Digital Comparator Control 7
    volatile uint32 RESSSS[9];    // Reserved
    volatile uint32 ADCDCCMP0;    // ADC Digital Comparator Range 0
    volatile uint32 ADCDCCMP1;    // ADC Digital Comparator Range 1
    volatile uint32 ADCDCCMP2;    // ADC Digital Comparator Range 2
    volatile uint32 ADCDCCMP3;    // ADC Digital Comparator Range 3
    volatile uint32 ADCDCCMP4;    // ADC Digital Comparator Range 4
    volatile uint32 ADCDCCMP5;    // ADC Digital Comparator Range 5
    volatile uint32 ADCDCCMP6;    // ADC Digital Comparator Range 6
    volatile uint32 ADCDCCMP7;    // ADC Digital Comparator Range 7
    volatile uint32 RESSSSS[88];  // Reserved
    volatile uint32 ADCPP;        // ADC Peripheral Properties
    volatile uint32 ADCPC;        // ADC Peripheral Configuration
    volatile uint32 ADCCC;        // ADC Clock Configuration
} ADC_RegType;

#endif
