/* 
 * File:   Slave_Interface.h
 * Author: rfisher
 *
 * Created on 27 July 2016, 11:10 AM
 */

#ifndef SLAVE_INTERFACE_H
#define	SLAVE_INTERFACE_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdint.h>

void Slave_Interface_Init(void);
void Read_Slave_Mux(void);
void Write_To_Slave_Mux(uint8_t Command);
void Copy_Slave_Data_To_Buffer(uint8_t *pData);
uint8_t Is_Slave_Mux_Active(void);
uint8_t Is_Slave_Light_Active(void);

#ifdef	__cplusplus
}
#endif

#endif	/* SLAVE_INTERFACE_H */

