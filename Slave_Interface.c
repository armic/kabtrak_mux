#include "Slave_Interface.h"
#include "I2C_Interface.h"
#include <xc.h>
#include <i2c.h>

#define SLAVE_ADDR      0xBE                // address for all slave MUX - set Rot Sw to 'F'
#define I2C_TIMEOUT_COUNT   0x80

static uint8_t MUX_Slave_Write( uint8_t ucControl, uint8_t ucData);
static uint8_t MUX_Slave_Read (uint8_t ucControl, uint8_t *ucDataArray, uint8_t Length);

static int8_t Slave_Active_Status = 0;
static uint8_t Inbuffer[I2C_PACKET_SIZE];

void Slave_Interface_Init(void)
{
    unsigned int config2, config1;

    /* Setup the I2C Bus to the Slave device. */
    /* Baud rate is set for 100 kHz */
    config2 = 0x172;                 // was 0x11
    /* Configure I2C for 7 bit address mode */
    config1 = (I2C2_ON & I2C2_IDLE_CON & I2C2_CLK_HLD &
             I2C2_IPMI_DIS & I2C2_7BIT_ADD &
             I2C2_SLW_DIS & I2C2_SM_DIS &
             I2C2_GCALL_DIS & I2C2_STR_EN &                    //I2C2_STR_DIS
             I2C2_NACK & I2C2_ACK_DIS & I2C2_RCV_DIS &
             I2C2_STOP_DIS & I2C2_RESTART_DIS &
             I2C2_START_DIS);

  OpenI2C2(config1,config2);
}

uint8_t Is_Slave_Mux_Active(void)
{
    if (Slave_Active_Status > 0)
        return 1;
    else
        return 0;
}

uint8_t Is_Slave_Light_Active(void)
{
    if ((Slave_Active_Status > 0) && (Inbuffer[0] & 0x10))
    {
        return 1;
    }
    else
        return 0;
}

void Write_To_Slave_Mux(uint8_t Command)
{
    if (Slave_Active_Status > 0)
    {
        MUX_Slave_Write(SLAVE_ADDR, Command);
    }
}

void Read_Slave_Mux(void)
{
    if(MUX_Slave_Read(SLAVE_ADDR, Inbuffer, I2C_PACKET_SIZE))
    {
        if (--Slave_Active_Status < 0)
        {
            Slave_Active_Status = 0;
        }
    }
    else
    {
         Slave_Active_Status = 20;
    }
    
}

void Copy_Slave_Data_To_Buffer(uint8_t *pData)
{
    /* Only apply the slave data if it's valid. */
    if (Slave_Active_Status > 0)
    {
        uint8_t x;
        
        *pData &= 0xF0;
        *pData |= (Inbuffer[10]>>4) & 0x0F; /* Add the top 4 bits to the bottom of pb_buff[10] */
        pData++;
        
        for (x = 1; x < 10; x++)
        {
            *pData = Inbuffer[x];
            pData++;
        }
    }
    else {
        /* No Slave connection, so just set all the bits for the slave. */
        uint8_t x;
        
        *pData |= 0x0F;
        pData++;
        
        for (x = 1; x < 10; x++)
        {
            *pData |= 0xFF;
            pData++;
        }
    }
    
}

static uint8_t MUX_Slave_Write( uint8_t ucControl, uint8_t ucData)
{
    
    
    IdleI2C2();                          // ensure module is idle
    StartI2C2();                         // initiate START condition
     while(I2C2CONbits.SEN);          // wait until start condition is over
    if ( I2C2STATbits.BCL )               // test for bus collision
    {
      return ( -1 );                    // return with Bus Collision error
    }
    else                                // start condition successful
    {
        MasterWriteI2C2( ucControl );      // write byte - R/W bit should be 0
        
        IdleI2C2();                      // ensure module is idle
        if ( !I2C2STATbits.ACKSTAT )     // test for ACK condition, if received
        {
            MasterWriteI2C2( ucData );   // data byte for EEPROM
        }
        else
        {
            StopI2C2();                  // Send Stop Condition
            return ( -2 );              // return with Not Ack error condition
        }
    }

   IdleI2C2();                           // ensure module is idle
   StopI2C2();                           // send STOP condition
   while ( I2C2CONbits.PEN );           // wait until stop condition is over
   if ( I2C2STATbits.BCL )                // test for bus collision
   {
     return ( -1 );                     // return with Bus Collision error
   }
   return ( 0 );                        // return with no error
   }

static uint8_t MUX_Slave_Read (uint8_t ucControl, uint8_t *ucDataArray, uint8_t Length)
{
    uint8_t TimeOutCnt = I2C_TIMEOUT_COUNT;
    
    I2C2STATbits.BCL = 0;       //ec- clear bus col flag
    I2C2STATbits.IWCOL = 0;       //ec- clear  wr col flag

    IdleI2C2();                              // ensure module is idle
    StartI2C2();                             // initiate START condition
    
    TimeOutCnt = I2C_TIMEOUT_COUNT;
    while (TimeOutCnt > 0 && I2C2CONbits.SEN ) TimeOutCnt--;              // wait until start condition is over
    if (TimeOutCnt == 0){ return -10; }
    
    if ( I2C2STATbits.BCL )                   // test for bus collision
    {
        return ( -1 );                      // return with Bus Collision error
    }
    else
    {
        if ( MasterWriteI2C2( ucControl+ 1 ) )       // write 1 byte
        {
            StopI2C2();                      // Send stop condition
            return ( -3 );                  // set error for write collision
        }

        IdleI2C2();                          // ensure module is idle
        if ( !I2C2STATbits.ACKSTAT )         // test for ACK condition, if received
        {
            if ( MastergetsI2C2( Length, ucDataArray, 200) )// read in multiple bytes  // version 2.01 changed from 15 to 21
            {
                return ( -1 );              // return with Bus Collision error
            }
             
            NotAckI2C2();                    // send not ACK condition
            TimeOutCnt = I2C_TIMEOUT_COUNT;
            while (TimeOutCnt > 0 &&  I2C2CONbits.ACKEN ) TimeOutCnt--;    // wait until ACK sequence is over
            if (TimeOutCnt == 0){ return -10; }
            
            StopI2C2();                      // send STOP condition
            TimeOutCnt = I2C_TIMEOUT_COUNT;
            while (TimeOutCnt > 0 &&  I2C2CONbits.PEN ) TimeOutCnt--;      // wait until stop condition is over
            if (TimeOutCnt == 0){ return -10; }
            
            if ( I2C2STATbits.BCL )           // test for bus collision
            {
                return ( -1 );              // return with Bus Collision error
            }
        }
        else
        {
            StopI2C2();                      // Send Stop Condition
            return ( -2 );                  // return with Not Ack error
        }
    }

    return ( 0 );                           // return with no error
}


