/*******************************************************************************
  
  
  
*******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "system.h"

#include "usb.h"
#include "usb_device_hid.h"

#include <stdint.h>
#include <stdbool.h>        /* For true/false definition */


#include "Timer.h"
#include "USB_Interface.h"
#include "LDR_Interface.h"
#include "I2C_Interface.h"
#include "Slave_Interface.h"

#define LED_D2          LATAbits.LATA14      // Green led

// *****************************************************************************
// Section: File Scope or Global Constants
// *****************************************************************************
const uint8_t FirmwareVersionNumber[2] = { 0x04/*Major*/, 0x00/* Minor */ }; 

/* To ensure thread safe access of the Outgoing Packet data, we need to use two buffers. One buffer is filled in the main thread,
 * the other is used in the interrupt for sending out, so the interrupt never sends out a half updated buffer. */
uint8_t Currently_Filling_Buffer = 0;
uint8_t Outgoing_Packet[2][21];

// *****************************************************************************
// Section: Function definition
// *****************************************************************************
static void Execute_Command(uint8_t Command);
static void Update_LED_Heart_Beat(void);

/******************************************************************************
 * Function:        int main(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        Sets CPU clock and initializes i2c.
 *****************************************************************************/
int main ( void )
{
    uint16_t LoopTimer;
    
    SYSTEM_Initialize(SYSTEM_STATE_USB_START);
    
    Init_Timer1();          // opens with set config bytes
    USBDeviceInit();
    USBDeviceAttach();
    
    Init_LDR();
    I2C1_Init();
    Slave_Interface_Init();
            
    
    LoopTimer = Get_Timer_Count();
            

    while( 1 )
    {
        if ((Get_Timer_Count() - LoopTimer) > 50)
        {
            /* This section defines the tasks which must be run exactly every 100ms for timing purposes.*/
            ClrWdt(); /* Kick the watchdog */
            Kick_Ext_WatchDog();
            
            LoopTimer += 50;
            
            /* Did we get any command we need to execute? */
            Execute_Command(Get_Command_To_Execute());
            
            /* Read the LDRs and the Slave Mux (if there is one) */
            ReadLDRs();
            Read_Slave_Mux();
            
            /* Bring the read in data into our out going buffer */
            Copy_LDR_To_Buffer(Outgoing_Packet[Currently_Filling_Buffer]);
            Copy_Slave_Data_To_Buffer(&Outgoing_Packet[Currently_Filling_Buffer][10]);
            
            /* We need to add the slave's light status to the out going buffer. */
            if (Is_Slave_Light_Active())
            {
               Outgoing_Packet[Currently_Filling_Buffer][0] |= 0x80;
            }
            else {
                Outgoing_Packet[Currently_Filling_Buffer][0] &= ~0x80;
            }
            
            Outgoing_Packet[Currently_Filling_Buffer][20] = CalcChecksum(Outgoing_Packet[Currently_Filling_Buffer], 20);
            
            /* We have a new buffer, so let the I2C interrupt know this is the latest one */
            Set_Outgoing_Packet(Outgoing_Packet[Currently_Filling_Buffer]);
            /* Change the buffer we're next going to update so the Interrupt never sends out a half filled buffer. */
            Currently_Filling_Buffer ^= 0x01;
            
            
        }
        
        //Application specific tasks
        USB_Interface_Fast_Poll();
        
        /* Update the flashing heart beat LED. */
        Update_LED_Heart_Beat();
    }
}


void Execute_Command(uint8_t Command)
{
    if (Command != 0xFF)
    {
        switch (Command)
        {
            case 0:
                Set_Light_Panel(OFF);
                break;
            case 1:
                Set_Light_Panel(ON);
                break;
            case 2:
                DRW_GRN = OFF;
                break;
            case 3:
                DRW_GRN = ON;
                break;
            case 4:
                DRW_RED = OFF;
                break;
            case 5:
                DRW_RED = ON;
                break;
            case 6:
                DRW_LOCK = OFF;
                break;
            case 7:
                DRW_LOCK = ON;
                break;
            default:
                /* Do nothing.. */
                break;
        }
        /* Now send the command on to the slave.. */
        Write_To_Slave_Mux(Command);
    }
}


static void Update_LED_Heart_Beat(void)
{
    static uint16_t LastUpdateTime = 0;
    static uint16_t ledCount = 0;
    static uint8_t  GlowCount = 0;
    static uint8_t ErrorFlash = 0;
    
        
    /* ONly run this function once per Ms */
    if (LastUpdateTime == Get_Timer_Count())
    {
        return;
    }
    
    LastUpdateTime = Get_Timer_Count();
    
    if (ledCount || GlowCount || Is_I2C_Active())
    {
        
        /* Slow brightening and darkening.. */
        ledCount++;

        if (ledCount > 20)
        {
            ledCount = 0;
            GlowCount++;
        }
        
        if (GlowCount > 81)
        {
            GlowCount = 0;
        }

        if (GlowCount <= 40)
        {
            if (ledCount < (GlowCount/2))
            {
                LED_D2 = 1;
            }
            else {
                LED_D2 = 0;
            }

        }
        else {
            if (ledCount <= (GlowCount-41)/2)
            {
                LED_D2 = 0;
            }
            else {
                LED_D2 = 1;

            }
        }
        
    }
    else {
        ErrorFlash++;
        if (ErrorFlash < 10)
        {
            LED_D2 = 1; /* I2C not active, so no LED */
        }
        else if (ErrorFlash < 100)
        {
            LED_D2 = 0; /* I2C not active, so no LED */
        }
        else {
            ErrorFlash = 0;
        }
    }
}



/*******************************************************************************
 End of File
*/
