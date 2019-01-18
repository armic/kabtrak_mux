/* 
 * File:   LDR_Interface.h
 * Author: rfisher
 *
 * Created on 27 July 2016, 1:11 PM
 */

#ifndef LDR_INTERFACE_H
#define	LDR_INTERFACE_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <stdint.h>
    
void Init_LDR(void);

void ReadLDRs(void);
void Copy_LDR_To_Buffer(uint8_t *pData);

void Set_Light_Panel(uint8_t Value);

#ifdef	__cplusplus
}
#endif

#endif	/* LDR_INTERFACE_H */

