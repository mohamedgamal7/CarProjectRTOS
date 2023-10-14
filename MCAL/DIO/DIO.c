/*
 * DIO.c
 *
 *  Created on: Aug 13, 2023
 *      Author: EUI-Support
 */

#include "DIO.h"
void PORTS_Operation(void){
    char i;
    PORT_CONFIG();
    for (i=0;i<Port_Num;i++){
        if (Ports_Operating[i]==0)
            continue;
        else {
            PORT_Init ((Port_Select)i,(PinConfig*) PortStruct_ptr[i]);
            GPIO_InterruptInit((Port_Select)i,(PinConfig*) PortStruct_ptr[i]);
        }
    }
    DIO_Set_Pullup(PORTF,P0|P4);
}
/*****************************************************************/
void PORT_Init (Port_Select Port,PinConfig *StructPtr)
{
    switch (Port){
    case PORTA:
        SYSCTL_RCGCGPIO_R|=PORTA_CC;
        while ((SYSCTL_PRGPIO_R&PORTA_CC)==0);
        GPIO_PORTA_LOCK_R=0X4C4F434B;
        GPIO_PORTA_CR_R=StructPtr->Pins.Pins_Data;
        GPIO_PORTA_DIR_R= StructPtr->Pin_DirectionHigh.Pins_Data;
        break;
    case PORTB:
        SYSCTL_RCGCGPIO_R|=PORTB_CC;
        while ((SYSCTL_PRGPIO_R&PORTB_CC)==0);
        GPIO_PORTB_LOCK_R|=0X4C4F434B;
        GPIO_PORTB_CR_R|=StructPtr->Pins.Pins_Data;
        GPIO_PORTB_DIR_R|= StructPtr->Pin_DirectionHigh.Pins_Data;
        break;
    case PORTC:
        SYSCTL_RCGCGPIO_R|=PORTC_CC;
        while ((SYSCTL_PRGPIO_R&PORTC_CC)==0);
        GPIO_PORTC_LOCK_R=0X4C4F434B;
        GPIO_PORTC_CR_R=StructPtr->Pins.Pins_Data;
        GPIO_PORTC_DIR_R= StructPtr->Pin_DirectionHigh.Pins_Data;
        break;
    case PORTD:
        SYSCTL_RCGCGPIO_R|=PORTD_CC;
        while ((SYSCTL_PRGPIO_R&PORTD_CC)==0);
        GPIO_PORTD_LOCK_R=0X4C4F434B;
        GPIO_PORTD_CR_R=StructPtr->Pins.Pins_Data;
        GPIO_PORTD_DIR_R= StructPtr->Pin_DirectionHigh.Pins_Data;
        break;
    case PORTE:
        SYSCTL_RCGCGPIO_R|=PORTE_CC;
        while ((SYSCTL_PRGPIO_R&PORTE_CC)==0);
        GPIO_PORTE_LOCK_R=0X4C4F434B;
        GPIO_PORTE_CR_R=StructPtr->Pins.Pins_Data;
        GPIO_PORTE_DIR_R= StructPtr->Pin_DirectionHigh.Pins_Data;
        break;
    case PORTF:
        SYSCTL_RCGCGPIO_R|=PORTF_CC;
        while ((SYSCTL_PRGPIO_R&PORTF_CC)==0);
        GPIO_PORTF_LOCK_R=0X4C4F434B;
        GPIO_PORTF_CR_R=StructPtr->Pins.Pins_Data;
        GPIO_PORTF_DIR_R= StructPtr->Pin_DirectionHigh.Pins_Data;
        break;
    default:
        SYSCTL_RCGCGPIO_R|=PORTS_CC;
        while ((SYSCTL_PRGPIO_R&PORTS_CC)==0);
        GPIO_PORTA_LOCK_R=0X4C4F434B;
        GPIO_PORTB_LOCK_R=0X4C4F434B;
        GPIO_PORTC_LOCK_R=0X4C4F434B;
        GPIO_PORTD_LOCK_R=0X4C4F434B;
        GPIO_PORTE_LOCK_R=0X4C4F434B;
        GPIO_PORTF_LOCK_R=0X4C4F434B;
    } //      GPIO_PORTF_CR_R=1<<PIN0|1<<PIN1|1<<PIN2|1<<PIN3|1<<PIN4;  //  GPIO_PORTF_DIR_R=1<<PIN1|1<<PIN2|1<<PIN3;  //
    if (StructPtr->PullUp_Down==HIGH)  //PULL-UP
    {
        switch(Port){
        case PORTA:
            GPIO_PORTA_PUR_R= StructPtr->Pull_Up.Pins_Data;  //PULL-UP INPUTS
            break;
        case PORTB:
            GPIO_PORTB_PUR_R=  StructPtr->Pull_Up.Pins_Data;  //PULL-UP INPUTS
            break;
        case PORTC:
            GPIO_PORTC_PUR_R=  StructPtr->Pull_Up.Pins_Data;  //PULL-UP INPUTS
            break;
        case PORTD:
            GPIO_PORTD_PUR_R= StructPtr->Pull_Up.Pins_Data;  //PULL-UP INPUTS
            break;
        case PORTE:
            GPIO_PORTE_PUR_R=  StructPtr->Pull_Up.Pins_Data;  //PULL-UP INPUTS
            break;
        case PORTF:
            GPIO_PORTF_PUR_R=  StructPtr->Pull_Up.Pins_Data;  //PULL-UP INPUTS
        }
    }
    else if (StructPtr->PullUp_Down==LOW) {   //PULL DOWN
        switch(Port){
        case PORTA:
            GPIO_PORTA_PDR_R= StructPtr->Pull_Down.Pins_Data;  //PULL-DOWN INPUTS
            break;
        case PORTB:
            GPIO_PORTB_PDR_R|=  StructPtr->Pull_Down.Pins_Data;  //PULL-DOWN INPUTS
            break;
        case PORTC:
            GPIO_PORTC_PDR_R=  StructPtr->Pull_Down.Pins_Data;  //PULL-DOWN INPUTS
            break;
        case PORTD:
            GPIO_PORTD_PDR_R= StructPtr->Pull_Down.Pins_Data;  //PULL-DOWN INPUTS
            break;
        case PORTE:
            GPIO_PORTE_PDR_R=  StructPtr->Pull_Down.Pins_Data;  //PULL-DOWN INPUTS
            break;
        case PORTF:
            GPIO_PORTF_PDR_R=  StructPtr->Pull_Down.Pins_Data;  //PULL-DOWN INPUTS
        }
    }
    switch(Port){
    case PORTA:
        GPIO_PORTA_DEN_R = StructPtr->Pins.Pins_Data; //ENABLING THE USED PINS
        break;
    case PORTB:
        GPIO_PORTB_DEN_R|=  StructPtr->Pins.Pins_Data;  //ENABLING THE USED PINS
        break;
    case PORTC:
        GPIO_PORTC_DEN_R=  StructPtr->Pins.Pins_Data;  //ENABLING THE USED PINS
        break;
    case PORTD:
        GPIO_PORTD_DEN_R=StructPtr->Pins.Pins_Data; //ENABLING THE USED PINS
        break;
    case PORTE:
        GPIO_PORTE_DEN_R=  StructPtr->Pins.Pins_Data;  //ENABLING THE USED PINS
        break;
    case PORTF:
        GPIO_PORTF_DEN_R=  StructPtr->Pins.Pins_Data;  //ENABLING THE USED PINS
    }
}
/*****************************************************************/
void GPIO_InterruptInit(Port_Select Port,PinConfig *StructPtr){
    if (StructPtr->Interrupts_Enable==LOW)
    {
        return;
    }
    else {
        switch(Port) {   /*CLEAR GPIOIM*/
        case PORTA:
            GPIO_PORTA_IM_R = 0x00; /*0: PREVENT INTERRUPTS     1: ALLOW INTERRUPTS*/
            GPIO_PORTA_IS_R= StructPtr->Level_Detection.Pins_Data;    //EDGE DETECTION
            GPIO_PORTA_IBE_R=StructPtr->Both_Edges.Pins_Data;         //GPIO Interrupt Event
            GPIO_PORTA_IEV_R=StructPtr->RisingFalling_Edge.Pins_Data;  // FALLING EDGE
            GPIO_PORTA_IM_R = StructPtr->Interrupt_Mask.Pins_Data;   /*********INTERRUPT MASKING************/
            NVIC_EN0_R=1<<0; /*ALLOWS INTERRUPTS IN GENERAL FOR PORTA*/
            break;
        case PORTB:
            GPIO_PORTB_IM_R = 0x00;  /*0: PREVENT INTERRUPTS     1: ALLOW INTERRUPTS*/
            GPIO_PORTB_IS_R= StructPtr->Level_Detection.Pins_Data;    //EDGE DETECTION
            GPIO_PORTB_IBE_R=StructPtr->Both_Edges.Pins_Data;         //GPIO Interrupt Event
            GPIO_PORTB_IEV_R=StructPtr->RisingFalling_Edge.Pins_Data;  // FALLING EDGE
            GPIO_PORTB_IM_R = StructPtr->Interrupt_Mask.Pins_Data;   /*********INTERRUPT MASKING************/
            NVIC_EN0_R=1<<1; /*ALLOWS INTERRUPTS IN GENERAL FOR PORTB*/
            break;
        case PORTC:
            GPIO_PORTC_IM_R = 0x00;  /*0: PREVENT INTERRUPTS     1: ALLOW INTERRUPTS*/
            GPIO_PORTC_IS_R= StructPtr->Level_Detection.Pins_Data;    //EDGE DETECTION
            GPIO_PORTC_IBE_R=StructPtr->Both_Edges.Pins_Data;         //GPIO Interrupt Event
            GPIO_PORTC_IEV_R=StructPtr->RisingFalling_Edge.Pins_Data;  // FALLING EDGE
            GPIO_PORTC_IM_R = StructPtr->Interrupt_Mask.Pins_Data;   /*********INTERRUPT MASKING************/
            NVIC_EN0_R=1<<2; /*ALLOWS INTERRUPTS IN GENERAL FOR PORTC*/
            break;
        case PORTD:
            GPIO_PORTD_IM_R = 0x00; /*0: PREVENT INTERRUPTS     1: ALLOW INTERRUPTS*/
            GPIO_PORTD_IS_R= StructPtr->Level_Detection.Pins_Data;    //EDGE DETECTION
            GPIO_PORTD_IBE_R=StructPtr->Both_Edges.Pins_Data;         //GPIO Interrupt Event
            GPIO_PORTD_IEV_R=StructPtr->RisingFalling_Edge.Pins_Data;  // FALLING EDGE
            GPIO_PORTD_IM_R = StructPtr->Interrupt_Mask.Pins_Data;   /*********INTERRUPT MASKING************/
            NVIC_EN0_R=1<<3; /*ALLOWS INTERRUPTS IN GENERAL FOR PORTD*/
            break;
        case PORTE:
            GPIO_PORTE_IM_R = 0x00;  /*0: PREVENT INTERRUPTS     1: ALLOW INTERRUPTS*/
            GPIO_PORTE_IS_R= StructPtr->Level_Detection.Pins_Data;    //EDGE DETECTION
            GPIO_PORTE_IBE_R=StructPtr->Both_Edges.Pins_Data;         //GPIO Interrupt Event
            GPIO_PORTE_IEV_R=StructPtr->RisingFalling_Edge.Pins_Data;  // FALLING EDGE
            GPIO_PORTE_IM_R = StructPtr->Interrupt_Mask.Pins_Data;   /*********INTERRUPT MASKING************/
            NVIC_EN0_R=1<<4; /*ALLOWS INTERRUPTS IN GENERAL FOR PORTE*/
            break;
        case PORTF:
            GPIO_PORTF_IM_R = 0x00;  /*0: PREVENT INTERRUPTS     1: ALLOW INTERRUPTS*/
            GPIO_PORTF_IS_R= StructPtr->Level_Detection.Pins_Data;    //EDGE DETECTION
            GPIO_PORTF_IBE_R=StructPtr->Both_Edges.Pins_Data;         //GPIO Interrupt Event
            GPIO_PORTF_IEV_R=StructPtr->RisingFalling_Edge.Pins_Data;  // FALLING EDGE
            GPIO_PORTF_IM_R = StructPtr->Interrupt_Mask.Pins_Data;   /*********INTERRUPT MASKING************/
            NVIC_EN0_R=1<<30; /*ALLOWS INTERRUPTS IN GENERAL FOR PORTF*/
        }//End of Switch Case
    }
}
/*****************************************************************/
void alt_Function(uint8 Port,uint8 pin, uint8 pinmux)
{
    switch (Port)
    {
    case PORTA:
        GPIO_PORTA_AFSEL_R|=(1<<pin) ; //ENABLING THE USED PINS
        GPIO_PORTA_PCTL_R|= pinmux<<(pin*4);
        break;
    case PORTB:
        GPIO_PORTB_AFSEL_R |=(1<<pin) ;  //ENABLING THE USED PINS
        GPIO_PORTB_PCTL_R|= pinmux<<(pin*4);
        break;
    case PORTC:
        GPIO_PORTC_AFSEL_R |=(1<<pin) ;  //ENABLING THE USED PINS
        GPIO_PORTC_PCTL_R|= pinmux<<(pin*4);
        break;
    case PORTD:
        GPIO_PORTD_AFSEL_R |=(1<<pin) ;//ENABLING THE USED PINS
        GPIO_PORTD_PCTL_R|= pinmux<<(pin*4);
        break;
    case PORTE:
        GPIO_PORTE_AFSEL_R |=(1<<pin) ;  //ENABLING THE USED PINS
        GPIO_PORTE_PCTL_R|= pinmux<<(pin*4);
        break;
    case PORTF:
        GPIO_PORTF_AFSEL_R |=(1<<pin) ;  //ENABLING THE USED PINS
        GPIO_PORTF_PCTL_R|= pinmux<<(pin*4);
    }
}
/*****************************************************************/
void analog_Mode(Port_Select Port,uint8 Pins){
    switch (Port)
    {
    case PORTA:
        GPIO_PORTA_AMSEL_R|=(Pins) ; //ENABLING THE USED PINS
        break;
    case PORTB:
        GPIO_PORTB_AMSEL_R |=(Pins) ;  //ENABLING THE USED PINS
        break;
    case PORTC:
        GPIO_PORTC_AMSEL_R |=(Pins) ;  //ENABLING THE USED PINS
        break;
    case PORTD:
        GPIO_PORTD_AMSEL_R |=(Pins) ;//ENABLING THE USED PINS
        break;
    case PORTE:
        GPIO_PORTE_AMSEL_R |=(Pins) ;  //ENABLING THE USED PINS
        break;
    case PORTF:
        GPIO_PORTF_AMSEL_R |=(Pins) ;  //ENABLING THE USED PINS
    }
}
/*****************************************************************/
void DIO_WritePin(Port_Select Port,Read_Write *StructPtr)
{
    switch(Port){
    case PORTA:
        GPIO_PORTA_DATA_R = StructPtr->WritePIN.Pins_Data;
        break;
    case PORTB:
        GPIO_PORTB_DATA_R   = StructPtr->WritePIN.Pins_Data;
        break;
    case PORTC:
        GPIO_PORTC_DATA_R = StructPtr->WritePIN.Pins_Data;
        break;
    case PORTD:
        GPIO_PORTD_DATA_R   = StructPtr->WritePIN.Pins_Data;
        break;
    case PORTE:
        GPIO_PORTE_DATA_R = StructPtr->WritePIN.Pins_Data;
        break;
    case PORTF:
        GPIO_PORTF_DATA_R = StructPtr->WritePIN.Pins_Data;
    }
}
void DIO_WritePort(Port_Select Port,Read_Write *StructPtr,char Set_Clear){
    if(Set_Clear==HIGH)/* SET PORT*/
    {
        switch(Port){
        case PORTA:
            GPIO_PORTA_DATA_R= 0xFF;   //PORTA SET
            break;
        case PORTB:
            GPIO_PORTB_DATA_R= 0xFF;   //PORTB SET
            break;
        case PORTC:
            GPIO_PORTC_DATA_R= 0xFF;   //PORTC SET
            break;
        case PORTD:
            GPIO_PORTD_DATA_R= 0xFF;   //PORTD SET
            break;
        case PORTE:
            GPIO_PORTE_DATA_R= 0xFF;   //PORTE SET
            break;
        case PORTF:
            GPIO_PORTF_DATA_R= 0xFF;   //PORTF SET
        }
    }
    else if(Set_Clear==LOW)/*CLEAR PORT*/
    {
        switch(Port){
        case PORTA:
            GPIO_PORTA_DATA_R= 0x00;   //PORTA CLEAR
            break;
        case PORTB:
            GPIO_PORTB_DATA_R= 0x00;   //PORTB CLEAR
            break;
        case PORTC:
            GPIO_PORTC_DATA_R= 0x00;   //PORTC CLEAR
            break;
        case PORTD:
            GPIO_PORTD_DATA_R= 0x00;   //PORTD CLEAR
            break;
        case PORTE:
            GPIO_PORTE_DATA_R= 0x00;   //PORTE CLEAR
            break;
        case PORTF:
            GPIO_PORTF_DATA_R= 0x00;   //PORTF CLEAR
        }
    }
    else
        return;
}
int DIO_ReadPin(Port_Select Port,Read_Write *StructPtr,char Bit){
    switch(Port){
    case PORTA:
        return Get_Bit(GPIO_PORTA_DATA_R,Bit);
    case PORTB:
        return Get_Bit(GPIO_PORTB_DATA_R,Bit);
    case PORTC:
        return Get_Bit(GPIO_PORTC_DATA_R,Bit);
    case PORTD:
        return Get_Bit(GPIO_PORTD_DATA_R,Bit);
    case PORTE:
        return Get_Bit(GPIO_PORTE_DATA_R,Bit);
    case PORTF:
        return Get_Bit(GPIO_PORTF_DATA_R,Bit);
    }
}
void DIO_ReadPort(Port_Select Port,Read_Write *StructPtr){
    switch(Port){
    case PORTA:
        StructPtr->ReadPORT =GPIO_PORTA_DATA_R;
        break;
    case PORTB:
        StructPtr->ReadPORT =GPIO_PORTB_DATA_R;
        break;
    case PORTC:
        StructPtr->ReadPORT =GPIO_PORTC_DATA_R;
        break;
    case PORTD:
        StructPtr->ReadPORT =GPIO_PORTD_DATA_R;
        break;
    case PORTE:
        StructPtr->ReadPORT =GPIO_PORTE_DATA_R;
        break;
    case PORTF:
        StructPtr->ReadPORT =GPIO_PORTF_DATA_R;
    }
}


void DIO_Write(uint8 CpyPort_ID, uint8 CpyPinMask, uint8 CpyValue)
{
    // use bit banding to write directly the value on the PORT
    ((volatile unsigned long *)GPIO_PORT_ADDRESS(NO_OFFSET))[CpyPinMask] = CpyValue;
}

uint8 DIO_Read(uint8 CpyPort_ID, uint8 CpyPinMask)
{
    // use bit banding to read the port
    return ((volatile unsigned long *)GPIO_PORT_ADDRESS(NO_OFFSET))[CpyPinMask];

}

void DIO_Set_Pullup(uint8 Cpy_Port,uint8 Cpy_PinMask)
{
    if(Cpy_Port<6)
    {
        switch(Cpy_Port){
        case PORTA:
            GPIO_PORTA_PUR_R|= Cpy_PinMask;  //PULL-UP INPUTS
            break;
        case PORTB:
            GPIO_PORTB_PUR_R|= Cpy_PinMask;  //PULL-UP INPUTS
            break;
        case PORTC:
            GPIO_PORTC_PUR_R|= Cpy_PinMask;  //PULL-UP INPUTS
            break;
        case PORTD:
            GPIO_PORTD_PUR_R|= Cpy_PinMask;  //PULL-UP INPUTS
            break;
        case PORTE:
            GPIO_PORTE_PUR_R|= Cpy_PinMask;  //PULL-UP INPUTS
            break;
        case PORTF:
            GPIO_PORTF_PUR_R|= Cpy_PinMask;  //PULL-UP INPUTS
        }
    }
}

