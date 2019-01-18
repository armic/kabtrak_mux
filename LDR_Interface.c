
#include <xc.h>
#include <stdint.h>
#include "system.h"
#include "LDR_Interface.h"
#include "Slave_Interface.h"
#include "LDR_Pin_Definitions.h"

#define DRWR_SW         PORTHbits.RH11      
#define LED_GRN_ST      PORTHbits.RH5       // drawer green led status
#define LED_RED_ST      PORTHbits.RH4       // drawer red led status
//#define DRW_LOCK_ST     PORTDbits.RD11      // drawer lock status







#define LDR_BYTE_COUNT  11



static void Debounce_Value(uint8_t NewVal, uint8_t Offset);

/* This is where we place the de-bounced LDR values. */
uint8_t LDR_Values[LDR_BYTE_COUNT];
uint8_t Light_Status;

void Init_LDR(void)
{
    /* Initalise the LEDs and set them to a known value*/
    IR_LED_Bank1_Port &= ~IR_LED_Bank1_Bit;
    IR_LED_Bank2_Port &= ~IR_LED_Bank2_Bit;
    IR_LED_Bank3_Port &= ~IR_LED_Bank3_Bit;
    
    /* default to the LEDs being off.*/
    Set_Light_Panel(OFF);
}

void Set_Light_Panel(uint8_t Value)
{
    Light_Status = Value;
    IR_LED_Bank1 = Value;
    IR_LED_Bank2 = Value;
    IR_LED_Bank3 = Value;
}

// Reads the logic status of each 100 LDRs and sets appropriate bits in 
// packedByte array
void ReadLDRs(void)
{
    uint8_t TmpValue;
// BYTE 0  ################
    TmpValue = 0;
    if(DRWR_SW)     { TmpValue |= 0x01; }
    if(LED_GRN_ST)  { TmpValue |= 0x02; }
    if(LED_RED_ST)  { TmpValue |= 0x04; }
//     if(DRW_LOCK_ST)
   // ** Used as LDR 01 **
        {
            TmpValue |= 0x08;
        }
//        else
//            packedByte[1] = packedByte[1] & 0xF7;

    if(Light_Status) { TmpValue |= 0x10; }
    
    if (Is_Slave_Mux_Active())
    {
        TmpValue |= 0x20;
        TmpValue |= 0x40;
    }
//    if(ch_slave_mux_present) { TmpValue |= 0x20; }
//    if(ch_slave_mux_comms) { TmpValue |= 0x40; }
    Debounce_Value(TmpValue, 0);

// BYTE 1   ######################
    TmpValue = 0;
    if(LDR_L08) { TmpValue |= 0x01; }
    if(LDR_L07) { TmpValue |= 0x02; }
    if(LDR_L06) { TmpValue |= 0x04; }
    if(LDR_L05) { TmpValue |= 0x08; }
    if(LDR_L04) { TmpValue |= 0x10; }
    if(LDR_L03) { TmpValue |= 0x20; }
    if(LDR_L02) { TmpValue |= 0x40; }
    if(LDR_L01) { TmpValue |= 0x80; }
    Debounce_Value(TmpValue, 1);
    

// BYTE 2 #############
    TmpValue = 0;
    if(LDR_L16) { TmpValue |= 0x01; }
    if(LDR_L15) { TmpValue |= 0x02; }
    if(LDR_L14) { TmpValue |= 0x04; }
    if(LDR_L13) { TmpValue |= 0x08; }
    if(LDR_L12) { TmpValue |= 0x10; }
    if(LDR_L11) { TmpValue |= 0x20; }
    if(LDR_L10) { TmpValue |= 0x40; }
    if(LDR_L09) { TmpValue |= 0x80; }
    Debounce_Value(TmpValue, 2);
    
// BYTE 3 #############
    TmpValue = 0;
    if(LDR_L24) { TmpValue |= 0x01; }
    if(LDR_L23) { TmpValue |= 0x02; }
    if(LDR_L22) { TmpValue |= 0x04; }
    if(LDR_L21) { TmpValue |= 0x08; }
    if(LDR_L20) { TmpValue |= 0x10; }
    if(LDR_L19) { TmpValue |= 0x20; }
    if(LDR_L18) { TmpValue |= 0x40; }
    if(LDR_L17) { TmpValue |= 0x80; }
    Debounce_Value(TmpValue, 3);

// BYTE 4 #############
    TmpValue = 0;
    if(LDR_L32) { TmpValue |= 0x01; }
    if(LDR_L31) { TmpValue |= 0x02; }
    if(LDR_L30) { TmpValue |= 0x04; }
    if(LDR_L29) { TmpValue |= 0x08; }
    if(LDR_L28) { TmpValue |= 0x10; }
    if(LDR_L27) { TmpValue |= 0x20; }
    if(LDR_L26) { TmpValue |= 0x40; }
    if(LDR_L25) { TmpValue |= 0x80; }
    Debounce_Value(TmpValue, 4);
    
// BYTE 5 #############
    TmpValue = 0;
    if(LDR_L40) { TmpValue |= 0x01; }
    if(LDR_L39) { TmpValue |= 0x02; }
    if(LDR_L38) { TmpValue |= 0x04; }
    if(LDR_L37) { TmpValue |= 0x08; }
    if(LDR_L36) { TmpValue |= 0x10; }
    if(LDR_L35) { TmpValue |= 0x20; }
    if(LDR_L34) { TmpValue |= 0x40; }
    if(LDR_L33) { TmpValue |= 0x80; }
    Debounce_Value(TmpValue, 5);
    
// BYTE 6 #############
    TmpValue = 0;
    if(LDR_L48) { TmpValue |= 0x01; }
    if(LDR_L47) { TmpValue |= 0x02; }
    if(LDR_L46) { TmpValue |= 0x04; }
    if(LDR_L45) { TmpValue |= 0x08; }
    if(LDR_L44) { TmpValue |= 0x10; }
    if(LDR_L43) { TmpValue |= 0x20; }
    if(LDR_L42) { TmpValue |= 0x40; }
    if(LDR_L41) { TmpValue |= 0x80; }
    Debounce_Value(TmpValue, 6);

// BYTE 7 #############
    TmpValue = 0;
    if(LDR_L56) { TmpValue |= 0x01; }
    if(LDR_L55) { TmpValue |= 0x02; }
    if(LDR_L54) { TmpValue |= 0x04; }
    if(LDR_L53) { TmpValue |= 0x08; }
    if(LDR_L52) { TmpValue |= 0x10; }
    if(LDR_L51) { TmpValue |= 0x20; }
    if(LDR_L50) { TmpValue |= 0x40; }
    if(LDR_L49) { TmpValue |= 0x80; }
    Debounce_Value(TmpValue, 7);

// BYTE 8 #############
    TmpValue = 0;
    if(LDR_L64) { TmpValue |= 0x01; }
    if(LDR_L63) { TmpValue |= 0x02; }
    if(LDR_L62) { TmpValue |= 0x04; }
    if(LDR_L61) { TmpValue |= 0x08; }
    if(LDR_L60) { TmpValue |= 0x10; }
    if(LDR_L59) { TmpValue |= 0x20; }
    if(LDR_L58) { TmpValue |= 0x40; }
    if(LDR_L57) { TmpValue |= 0x80; }
    Debounce_Value(TmpValue, 8);

    // BYTE 9 #############
    TmpValue = 0;
    if(LDR_L72) { TmpValue |= 0x01; }
    if(LDR_L71) { TmpValue |= 0x02; }
    if(LDR_L70) { TmpValue |= 0x04; }
    if(LDR_L69) { TmpValue |= 0x08; }
    if(LDR_L68) { TmpValue |= 0x10; }
    if(LDR_L67) { TmpValue |= 0x20; }
    if(LDR_L66) { TmpValue |= 0x40; }
    if(LDR_L65) { TmpValue |= 0x80; }
    Debounce_Value(TmpValue, 9);

// BYTE 10 #############
    
    TmpValue = 0x10; 
    /* What happend to L76? */
    if(LDR_L75) { TmpValue |= 0x20; }
    if(LDR_L74) { TmpValue |= 0x40; }
    if(LDR_L73) { TmpValue |= 0x80; }
    Debounce_Value(TmpValue, 10);
}

void Copy_LDR_To_Buffer(uint8_t *pData)
{
    uint8_t x;
    for (x=0; x < 10; x++)
    {
        *pData = LDR_Values[x];
        pData++;
    }
    /* The 10th value is only partial, so do a special update for it. */
    *pData &= 0x0F; /* Clear the bits we're controlling.. */
    *pData |= (0xF0 & LDR_Values[10]); /* and copy the new value in.. */
}

/* This functions de-bounces the entire byte value, not the individual bits. Do we need it to work on the bit value or is this close enough? */
static void Debounce_Value(uint8_t NewVal, uint8_t Offset)
{
    static uint8_t Debounce_Buffer[LDR_BYTE_COUNT];
    
    /* If the Stored De bounce value is the same as the new value, but different from the LDR Value, update the LDR value.
     * (eg the value has been the same for two passes, so we update our final stored value.) */
    if ((NewVal ^ Debounce_Buffer[Offset]) == 0 &&
        (LDR_Values[Offset] ^ Debounce_Buffer[Offset]) != 0)
    {
        LDR_Values[Offset] = Debounce_Buffer[Offset];
    }
    /* If the New value is different from the stored de bounce value, then store the new de bounced value. */
    else if ((NewVal ^ Debounce_Buffer[Offset]) != 0)
    {
        Debounce_Buffer[Offset] = NewVal;
    }
}